#include "MyLogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string func(const char *msg)
{
    string s1 = string(__FILE__) + string(":") 
                + string(__FUNCTION__) + string(":")
                + string(std::to_string(__LINE__)) 
                + string(":") + msg;
    return s1;
}


void test()
{
    Mylogger *plog = Mylogger::getInstance();
    /* plog->info("This is an info message"); */
    /* plog->info(func("This is an info message").c_str()); */
    /* plog->info(prefix("This is an info message")); */
    /* plog->error(prefix("This is an error message")); */
    /* plog->debug(prefix("This is an debug message")); */
    /* plog->warn(prefix("This is an warn message")); */

    logInfo("This is an info message");
    logError("This is an error message");
}

void test2()
{
    cout << __FILE__ << "   " 
         << __FUNCTION__ << "  " 
         << __LINE__ << endl; 
}

int main(int argc, char **argv)
{
    test();
    return 0;
}

