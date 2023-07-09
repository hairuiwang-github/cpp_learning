#include <iostream>

using std::cout;
using std::endl;

//1、单例模式自动释放的解决方式1：使用友元类
class Singleton
{
    friend class AutoRelease;//友元类
public:
    static Singleton *getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
        }

        return _pInstance;
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

Singleton *Singleton::_pInstance = nullptr;

class AutoRelease
{
public:
    AutoRelease()
    {
        cout << "AutoRelease()" << endl;
    }

    ~AutoRelease()
    {
        cout << "~AutoRelease()" << endl;
        if(Singleton::_pInstance)
        {
            delete Singleton::_pInstance;
            Singleton::_pInstance = nullptr;
        }
    }
};
int main(int argc, char **argv)
{
    Singleton *ps = Singleton::getInstance();
    AutoRelease ar;//ar栈对象,当栈对象生命周期结束后执行析构函数，释放单例模式的资源

    return 0;
}
