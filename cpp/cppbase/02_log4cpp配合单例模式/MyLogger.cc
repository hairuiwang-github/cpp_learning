#include "MyLogger.h"
#include <iostream>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;

Mylogger *Mylogger::_pInstance = nullptr;

Mylogger *Mylogger::getInstance()
{
    if(nullptr == _pInstance)
    {
        _pInstance = new Mylogger();
    }

    return _pInstance;
}

void Mylogger::destroy()
{
    if(_pInstance)
    {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void Mylogger::warn(const char * msg)
{
    _mycat.warn(msg);
}

void Mylogger::error(const char * msg)
{
    _mycat.error(msg);
}

void Mylogger::debug(const char * msg)
{
    _mycat.debug(msg);
}

void Mylogger::info(const char * msg)
{
    _mycat.info(msg);
}

Mylogger::Mylogger()
: _mycat(Category::getRoot().getInstance("mycat"))
{
    cout << "MyLogger()" << endl;
    //日志的格式
    PatternLayout *ppl1 = new PatternLayout();
    ppl1->setConversionPattern("%d %c [%p] %m%n");

    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d %c [%p] %m%n");

    //日志的目的地
    OstreamAppender *pos = new OstreamAppender("111", &cout);
    pos->setLayout(ppl1);

    FileAppender *pfa = new FileAppender("file", "wd.txt");
    pfa->setLayout(ppl2);

    //需要将appender添加到Category
    _mycat.addAppender(pos);
    _mycat.addAppender(pfa);

    //日志过滤器
    _mycat.setPriority(Priority::DEBUG);
}

Mylogger::~Mylogger()
{
    cout << "~MyLogger()" << endl;
    Category::shutdown();
}
