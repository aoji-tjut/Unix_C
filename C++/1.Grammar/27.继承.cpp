#include <iostream>
using namespace std;

class Father
{
public:
    Father()
    {
        cout << "Father构造函数" << endl;
        this->father_age = 40;
    }

    ~Father()
    {
        cout << "Father析构函数" << endl;
    }

    void PrintFather()
    {
        cout << &this->father_age << " " << this->father_age << endl;
    }

protected:
    int father_age;
private:
    int temp;
};

class Son : public Father
{
public:
    Son()
    {
        cout << "Son构造函数" << endl;
        this->son_age = 10;
    }

    ~Son()
    {
        cout << "Son析构函数" << endl;
    }

    void PrintSon()
    {
        cout << &this->father_age << " " << this->father_age << endl;
        cout << &this->son_age << " " << this->son_age << endl;
    }

private:
    int son_age;
};

int main()
{
    {
        Father father;
        cout << sizeof(father) << endl;
        father.PrintFather();
    }
    cout << endl;

    {
        Son son;
        cout << sizeof(son) << endl;    //私有成员也会继承 只是不能访问 考虑地址补齐
        son.PrintFather();
        son.PrintSon();
    }

    return 0;
}