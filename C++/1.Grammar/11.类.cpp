#include <iostream>
using namespace std;

//默认private
class Student
{
public:
    void Show()
    {
        cout << this->age << endl;
    }

private:
    int age = 20;
};

int main()
{
    Student stu;
    stu.Show();

    Student* p = new Student;
    p->Show();
    delete p;
    p = nullptr;

    return 0;
}