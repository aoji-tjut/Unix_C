#include <iostream>
using namespace std;

int main()
{
    //整型
    cout << "short\t\t" << sizeof(short) << endl;               //2字节 -2^15~2^15-1
    cout << "int\t\t\t" << sizeof(int) << endl;                 //4字节 -2^31~2^31-1
    cout << "long\t\t" << sizeof(long) << endl;                 //32位4字节 -2^31~2^31-1 64位8字节 -2^63~2^63-1
    cout << "long long\t" << sizeof(long long) << endl;         //8字节 -2^63~2^63-1

    //浮点型
    cout << "float\t\t" << sizeof(float) << endl;               //4字节 7位有效数字
    cout << "double\t\t" << sizeof(double) << endl;             //8字节 15~16位有效数字
    cout << "long double\t" << sizeof(long double) << endl;     //16字节 18~19位有效数字

    //字符型
    cout << "char\t\t" << sizeof(char) << endl;                 //1字节

    //bool型
    cout << "bool\t\t" << sizeof(bool) << endl;                 //1字节

    //指针
    cout << "int*\t\t" << sizeof(int*) << endl;                 //任何指针 32位4字节 64位8字节

    //数组
    int a[10];
    cout << "a[10]\t\t" << sizeof(a) << endl;                   //4*10字节

    //结构体
    struct Struct
    {
        //以占用字节最大的类型进行补齐
        char c;     //第一行地址1/8
        int i;      //第一行地址5/8
        double d;   //第二行地址8/8
    };
    cout << "Struct\t\t" << sizeof(Struct) << endl;             //以占用字节最大的类型进行地址补齐

    //联合
    union Union
    {
        //同一时刻只能存在一种类型 使用同一块内存
        char c;
        int i;
        double d;
    };
    cout << "Union\t\t" << sizeof(Union) << endl;               //占用字节最大的类型

    //枚举
    enum Enum
    {
        MON, TUE, WED, THU, FRI, SAT, SUN                       //后面元素的值依次+1
    };
    cout << "Enum\t\t" << sizeof(Enum) << endl;                 //无论多少元素只占4字节

    return 0;
}
