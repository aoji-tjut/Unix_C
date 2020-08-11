#include <iostream>
#include <vector>
#include <algorithm>    //关联式容器使用容器自带的find
using namespace std;

class Student
{
public:
    Student(int num, int age)
    {
        this->num = num;
        this->age = age;
    }

    //重载==
    bool operator==(const Student& stu)     //必须const修饰
    {
        return (this->num == stu.num) && (this->age == stu.age);
    }

    int num;
    int age;
};

int main()
{
    vector<int> v1;
    v1.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    auto it1 = find(v1.begin(), v1.end(), 5);      //查找5 返回迭代器
    if(it1 == v1.end())
    {
        cout << "未找到" << endl;
    } else
    {
        cout << "找到：" << *it1 << endl;
    }

    vector<Student> v2;
    Student stu1(1, 10);
    Student stu2(2, 20);
    Student stu3(3, 30);
    v2.push_back(move(stu1));
    v2.push_back(move(stu2));
    v2.push_back(move(stu3));
    auto it2 = find(v2.begin(), v2.end(), Student(3, 30));
    if(it2 == v2.end())
    {
        cout << "未找到" << endl;
    } else
    {
        cout << "找到：" << it2->num << " " << it2->age << endl;
    }

    return 0;
}