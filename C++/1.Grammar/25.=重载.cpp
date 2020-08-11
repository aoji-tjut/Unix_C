#include <iostream>
using namespace std;

class Student
{
public:
    Student(int num)
    {
        this->num = new int(num);
    }

    ~Student()
    {
        if(this->num)
        {
            delete num;
            this->num = nullptr;
        }
    }

    int GetNum()
    {
        return *this->num;
    }

    //=重载 主要针对于堆区
    Student& operator=(Student& stu);

private:
    int* num;
};

Student& Student::operator=(Student& stu)
{
    if(this->num)
    {
        delete num;
        this->num = nullptr;
    }
    this->num = new int(*stu.num);
    return *this;
}

int main()
{
    Student stu1(10);
    Student stu2(20);
    Student stu3(30);
    cout << stu1.GetNum() << endl;
    cout << stu2.GetNum() << endl;
    cout << stu3.GetNum() << endl;
    cout << endl;

    stu1 = stu2 = stu3;
    cout << stu1.GetNum() << endl;
    cout << stu2.GetNum() << endl;
    cout << stu3.GetNum() << endl;

    return 0;
}