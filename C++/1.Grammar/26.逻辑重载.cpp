#include <iostream>
using namespace std;

class Student
{
public:
    Student(int num)
    {
        this->num = num;
    }

    //||重载
    bool operator||(Student& stu);
    //&&重载
    bool operator&&(Student& stu);
    //==重载
    bool operator==(Student& stu);
    //！=重载
    bool operator!=(Student& stu);

private:
    int num;
};

bool Student::operator||(Student& stu)
{
    return (this->num || stu.num);
}

bool Student::operator&&(Student& stu)
{
    return (this->num && stu.num);
}

bool Student::operator==(Student& stu)
{
    return (this->num == stu.num);
}

bool Student::operator!=(Student& stu)
{
    return (this->num != stu.num);
}

int main()
{
    Student stu1(0);
    Student stu2(1);
    cout << (stu1 || stu2) << endl;
    cout << (stu1 && stu2) << endl;
    cout << (stu1 == stu2) << endl;
    cout << (stu1 != stu2) << endl;

    return 0;
}