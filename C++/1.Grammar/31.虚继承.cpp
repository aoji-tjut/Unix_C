#include <iostream>
using namespace std;

//临时类
class Temp
{
public:
    Temp()
    {
        cout << "Temp" << endl;
    }
};

//虚基类
class Father
{
public:
    Father()
    {
        cout << "Father" << endl;
        this->father_age = 50;
    }

    void PrintAge()
    {
        cout << "Father::PrintAge" << endl;
        cout << this->father_age << endl;
    }

protected:
    int father_age;
};

//Son虚继承Father 继承Temp
class Son : public Temp, virtual public Father
{
public:
    Son()
    {
        cout << "Son" << endl;
        this->son_age = 25;
    }

    void PrintAge()
    {
        cout << "Son::PrintAge" << endl;
        cout << this->father_age << endl;
        cout << this->son_age << endl;
    }

protected:
    int son_age;
};

//Daughter虚继承Father 继承Temp
class Daughter : public Temp, virtual public Father
{
public:
    Daughter()
    {
        cout << "Daughter" << endl;
        this->daughter_age = 20;
    }

    void PrintAge()
    {
        cout << "Daughter::PrintAge" << endl;
        cout << this->father_age << endl;
        cout << this->daughter_age << endl;
    }

protected:
    int daughter_age;
};

//Baby继承Son、Daughter、Father
class Baby : public Son, public Daughter
{
public:
    Baby()
    {
        cout << "Baby" << endl;
        this->baby_age = 1;
    }

    void PrintAge()
    {
        cout << "Baby::PrintAge" << endl;
        cout << this->father_age << endl;
        cout << this->son_age << endl;
        cout << this->daughter_age << endl;
        cout << this->baby_age << endl;
    }

private:
    int baby_age;
};

int main()
{
    Father father;
    father.PrintAge();
    cout << endl;

    Son son;            //构造函数虚继承优先于普通继承
    son.PrintAge();
    cout << endl;

    Daughter daughter;  //构造函数虚继承优先于普通继承
    daughter.PrintAge();
    cout << endl;

    Baby baby;          //构造函数同声明顺序
    baby.PrintAge();

    return 0;
}
