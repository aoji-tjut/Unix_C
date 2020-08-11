#include <iostream>
using namespace std;

class String
{
public:
    void Init(const char* str)
    {
        this->str = new char[this->len + 1];
        memcpy(this->str, str, this->len);
        this->str[this->len] = '\0';
    }

    static String ReturnTempObj()
    {
        String s("hello world");

        return s;
    }

    String()
    {
        cout << "String()\t\t\t\t\t" << this << endl;

        this->len = 0;
        this->str = nullptr;
    }

    String(const char* str)
    {
        cout << "String(const char* str)\t\t" << this << endl;

        this->len = strlen(str);
        Init(str);
    }

    String(const String& s)
    {
        cout << "String(const String& s)\t\t" << this << endl;

        this->len = s.len;
        Init(s.str);
    }

    String(String&& s) noexcept
    {
        cout << "String(String&& s)\t\t\t" << this << endl;

        this->len = s.len;
        this->str = s.str;
        s.len = 0;
        s.str = nullptr;    //防止指针析构两次
    }

    String& operator=(String& s)
    {
        cout << "operator=(String& s)\t\t" << this << endl;

        if(this != &s)
        {
            if(this->str)
            {
                delete[] this->str;
            }

            this->len = s.len;
            Init(s.str);
        }

        return *this;
    }

    String& operator=(String&& s) noexcept
    {
        cout << "operator=(String&& s)\t\t" << this << endl;

        if(this != &s)
        {
            if(this->str)
            {
                delete[] this->str;
            }

            this->len = s.len;
            this->str = s.str;
            s.len = 0;
            s.str = nullptr;    //防止指针析构两次
        }

        return *this;
    }

    ~String()
    {
        cout << "~String()\t\t\t\t" << this << endl;

        if(this->str)
        {
            delete[] str;
        }
    }

private:
    char* str;
    int len;
};

void Fun(int& i)
{
    cout << "Fun(int& i)\t\t" << &i << " " << i << endl;
}

void Fun(int&& i)
{
    cout << "Fun(int&& i)\t" << &i << " " << i << endl;
}

void Swap(int& a, int& b)
{
    int temp;
    temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

int main()
{
    //左值：可以出现在operator=左侧
    //右值：只能出现在operator=右侧 没有名称 不能取地址
    //移动语义：指针浅拷贝 move后原指针失效
    //临时对象是右值 临时对象作为函数实参 即右值引用移动语义
    //std::move()强制将左值转为右值实现移动语义

    {
        String s1("hello world");
        String s2(s1);
        String s3(String::ReturnTempObj());     //move
        String s4(std::move(s1));               //move move后s1为空
        String s5;
        s5 = s2;
        String s6;
        s6 = String("hello world");             //move
    }
    cout << endl;

    {
        int i = 10;
        cout << "\t\t\t\t" << &i << " " << i << endl;
        Fun(i);
        Fun(std::move(i));
        Fun(10);
    }
    cout << endl;

    {
        int i = 10, j = 20;
        cout << i << " " << j << endl;
        Swap(i, j);
        cout << i << " " << j << endl;
    }

    return 0;
}