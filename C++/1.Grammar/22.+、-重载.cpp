#include <iostream>
using namespace std;

class Student
{
public:
    Student(int score)
    {
        this->score = score;
    }

    int GetScore()
    {
        return this->score;
    }

    //类内运算符重载 第一个参数是隐含参数this
    int operator+(Student& stu);

private:
    int score;
};

//类外实现
int Student::operator+(Student& stu)
{
    return this->score + stu.score;
}

//类外运算符重载
int operator-(Student& stu1, Student& stu2)
{
    return stu1.GetScore() - stu2.GetScore();
}

int main()
{
    Student stu1(70);
    Student stu2(60);

    cout << stu1 + stu2 << endl;
    cout << stu1.operator+(stu2) << endl;       //本质
    cout << endl;

    cout << stu1 - stu2 << endl;
    cout << operator-(stu1, stu2) << endl;      //本质

    return 0;
}