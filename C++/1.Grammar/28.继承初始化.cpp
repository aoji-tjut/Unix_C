#include <iostream>
using namespace std;

class GrandFather
{
public:
    GrandFather(int grandfather_age)
    {
        cout << "GrandFather构造函数" << endl;
        this->grandfather_age = grandfather_age;
    }

protected:
    int grandfather_age;
};

class Father : public GrandFather
{
public:
    Father(int grandfather_age, int father_age) : GrandFather(grandfather_age)
    {
        cout << "Father构造函数" << endl;
        this->father_age = father_age;
    }

protected:
    int father_age;
};

class Son : public Father
{
public:
    //只能使用初始化列表给父类初始化
    Son(int grandfather_age, int father_age, int son_age) : Father(grandfather_age, father_age)
    {
        cout << "Son构造函数" << endl;
        this->son_age = son_age;
    }

    void PrintSon()
    {
        cout << this->grandfather_age << endl;
        cout << this->father_age << endl;
        cout << this->son_age << endl;
    }

private:
    int son_age;
};

int main()
{
    Son son(70, 40, 10);
    son.PrintSon();

    return 0;
}
