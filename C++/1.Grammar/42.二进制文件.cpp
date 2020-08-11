#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
public:
    string name;
    int age;
};

void Write()
{
    //创建流对象
    fstream fs;

    //打开文件
    fs.open("./二进制文件.txt", ios::binary | ios::out);     //二进制写形式打开

    //写入
    Student stu;
    stu.name = "敖吉";
    stu.age = 22;
    fs.write((char*) &stu, sizeof(stu));

    //关闭文件
    fs.close();
}

void Read()
{
    //创建流对象
    fstream fs;

    //打开文件
    fs.open("./二进制文件.txt", ios::binary | ios::in);     //二进制读形式打开

    //判断文件是否打开成功
    if(!fs.is_open())
    {
        cout << "文件打开失败！" << endl;
        exit(0);
    }

    //读取
    Student stu;
    fs.read((char*) &stu, sizeof(stu));
    cout << stu.name << " " << stu.age << endl;

    //关闭文件
    fs.close();
}

int main()
{
    Write();
    Read();

    return 0;
}