#include <iostream>
#include <vector>
#include <algorithm>
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

bool FindInt(int i)
{
    return i > 5;
}

bool FindStudent(Student& stu)
{
    return stu.num > 1;
}

int main()
{
    vector<int> v1;
    v1.reserve(10);
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    for(auto it = v1.begin(); it != v1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << count_if(v1.begin(), v1.end(), FindInt) << endl;     //条件统计大于5出现的次数

    vector<Student> v2;
    Student stu1(1, 10);
    Student stu2(2, 20);
    Student stu3(3, 30);
    v2.push_back(move(stu1));
    v2.push_back(move(stu2));
    v2.push_back(move(stu3));
    cout << count_if(v2.begin(), v2.end(), FindStudent) << endl;

    return 0;
}