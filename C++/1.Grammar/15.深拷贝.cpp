#include <iostream>
using namespace std;

class Student
{
public:
    Student(int age)
    {
        cout << "构造函数" << endl;
        this->age = new int(age);
    }

    //深拷贝 避免重复释放堆区内存
    Student(const Student& stu)
    {
        cout << "深拷贝构造" << endl;
        this->age = new int(*(stu.age));
    }

    ~Student()
    {
        cout << "析构函数 " << age << " ";
        //释放堆区
        if(this->age)
        {
            delete this->age;
            this->age = nullptr;
        }
        cout << this->age << endl;
    }

    void Show()
    {
        cout << this->age << " " << *(this->age) << endl;
    }

private:
    int* age;   //堆区
};

int main()
{
    Student stu(20);
    Student stu1 = stu;
    cout << endl;

    stu.Show();
    stu1.Show();
    cout << endl;

    return 0;
}