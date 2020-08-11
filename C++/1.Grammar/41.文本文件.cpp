#include <iostream>
#include <fstream>
using namespace std;

/*
 *ios::in       读
 *ios::out      写
 *ios::ate      初始位置文件尾
 *ios::app      文件尾追加
 *ios::trunc    如果文件存在则删除再创建
 *ios::binary   二进制方式
 *
 *fs.is_open()  判断文件是否存在
 *fs.eof()      判断文件是否为空
 */

void Write()
{
    //创建流对象
    fstream fs;

    //打开文件
    fs.open("./文本文件.txt", ios::out);   //路径 写打开

    //写入
    fs << "姓名：敖吉" << endl;
    fs << "学校：天津理工大学" << endl;
    fs << "学院：计算机科学与工程学院" << endl;

    //关闭文件
    fs.close();
}

void Read()
{
    //创建流对象
    fstream fs;

    //打开文件
    fs.open("./文本文件.txt", ios::in);   //路径 读打开

    //判断文件是否打开成功
    if(!fs.is_open())
    {
        cout << "文件打开失败！" << endl;
        exit(0);
    }

    //读取
    //1
    char buf1[128] = {0};
    while(fs >> buf1)
    {
        cout << buf1 << endl;
    }
    cout << endl;
    fs.clear();             //重制文件流
    fs.seekg(0, ios::beg);  //修改get指针位置 偏移量0 从流开始位置计算位移

    //2
    char buf2[128] = {0};
    while(fs.getline(buf2, sizeof(buf2)))
    {
        cout << buf2 << endl;
    }
    cout << endl;
    fs.clear();
    fs.seekg(0, ios::beg);

    //3
    string buf3;
    while(getline(fs, buf3))
    {
        cout << buf3 << endl;
    }
    cout << endl;
    fs.clear();
    fs.seekg(0, ios::beg);

    //4
    char c;
    while((c = fs.get()) != EOF)
    {
        cout << c;
    }

    //关闭文件
    fs.close();
}

int main()
{
    Write();
    Read();

    return 0;
}