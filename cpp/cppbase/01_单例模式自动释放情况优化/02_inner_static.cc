#include <iostream>

using std::cout;
using std::endl;

// 2、单例模式自动释放的解决方式2：内部类 + 静态数据成员

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if (nullptr == _pInstance)
        {
            _pInstance = new Singleton(); // 堆对象
        }

        return _pInstance;
    }

private:
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
            if (_pInstance)
            {
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };

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
    static AutoRelease _ar; //_ar栈对象
};

/* Singleton *Singleton::_pInstance = nullptr; */
Singleton *Singleton::_pInstance = getInstance();
Singleton::AutoRelease Singleton::_ar; //_ar静态对象

int main(int argc, char **argv)
{
    Singleton *ps1 = Singleton::getInstance();
    //利用静态对象生命周期结束，执行析构，实现单例模式自动释放
    return 0;
}