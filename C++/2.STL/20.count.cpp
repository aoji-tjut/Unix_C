#include <iostream>
#include <vector>
#include <algorithm>    //关联式容器使用容器自带的count
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
        v1.push_back(rand() % 5);
    }
    for(auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << count(v1.begin(), v1.end(), 3) << endl;     //统计3出现的次数

    vector<Student> v2;
    Student stu1(1, 10);
    Student stu2(2, 20);
    Student stu3(2, 20);
    Student stu4(3, 30);
    v2.push_back(move(stu1));
    v2.push_back(move(stu2));
    v2.push_back(move(stu3));
    v2.push_back(move(stu4));
    cout << count(v2.begin(), v2.end(), Student(2, 20)) << endl;

    return 0;
}