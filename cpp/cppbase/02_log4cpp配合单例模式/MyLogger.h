#ifndef __MYLOGGER_H__
#define __MYLOGGER_H__

#include <log4cpp/Category.hh>

using namespace log4cpp;

class Mylogger
{
public:
    static Mylogger *getInstance();
    static void destroy();

    void warn(const char * msg);
    void error(const char * msg);
    void debug(const char * msg);
    void info(const char * msg);

private:
    Mylogger();
    ~Mylogger();
private:
    static Mylogger *_pInstance;
    Category &_mycat;
};

#define prefix(msg) (string(__FILE__) + string(":") \
                    + string(__FUNCTION__) + string(":") \
                    + string(std::to_string(__LINE__)) \
                    + string(":") + msg).c_str()

#define logError(msg) Mylogger::getInstance()->error(prefix(msg))
#define logInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define logWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define logDebug(msg) Mylogger::getInstance()->debug(prefix(msg))

#endif
