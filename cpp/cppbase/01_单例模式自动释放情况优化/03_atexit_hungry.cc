#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;

//3、单例模式自动释放的3：atexit + 饿汉模式
//
class Singleton
{
public:
    static Singleton *getInstance()
    {
        //多线程安全问题,使用饿汉模式解决，一开始就获取资源
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
            //atexit执行一次,后续会回收资源一次,destroy()
            atexit(destroy);
        }

        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

private:
    static Singleton *_pInstance;
};

/* Singleton *Singleton::_pInstance = nullptr; //饱汉模式 */
Singleton *Singleton::_pInstance = getInstance();//饿汉模式

int main(int argc, char **argv)
{
    Singleton *ps = Singleton::getInstance();

    return 0;
}