#include <iostream>
using namespace std;

#define PI 3.14

//包含纯虚函数的类为抽象类 全部为纯虚函数的类为接口类 抽象类和接口类均不能实例化对象
//抽象类
class Math
{
public:
    Math()
    {
        cout << "Math构造" << endl;
    }

    //纯虚函数 类内没有实现 只能用作接口 需要子类重写进行实现
    virtual double GetPerimeter() = 0;
    virtual double GetArea() = 0;

    //纯虚析构必须进行实现
    virtual ~Math()
    {
        cout << "Math析构" << endl;
    }
};

class Circle : public Math
{
public:
    Circle(double r)
    {
        cout << "Circle构造" << endl;
        this->r = r;
    }

    double GetPerimeter() override
    {
        return 2 * PI * r;
    }

    double GetArea() override
    {
        return PI * r * r;
    }

    ~Circle() override
    {
        cout << "Circle析构" << endl;
    }

private:
    double r;
};

class Rect : public Math
{
public:
    Rect(double length, double width)
    {
        cout << "Rect构造" << endl;
        this->length = length;
        this->width = width;
    }

    double GetPerimeter() override
    {
        return 2 * (length + width);
    }

    double GetArea() override
    {
        return length * width;
    }

    ~Rect() override
    {
        cout << "Rect析构" << endl;
    }

private:
    double length;
    double width;
};

int main()
{
    Math* p = nullptr;
    int flag = 0;

    cout << "intput '1' Circle" << " / " << "intput '2' Rect" << endl;
    cin >> flag;
    switch(flag)
    {
        case 1:
        {
            cout << "intput 'r'" << endl;
            double r = 0.0;
            cin >> r;
            p = new Circle(r);
            cout << "GetPerimeter=" << p->GetPerimeter() << endl;
            cout << "Area=" << p->GetArea() << endl;
            delete p;
            break;
        }
        case 2:
        {
            cout << "intput 'length'、'width'" << endl;
            double length = 0.0;
            double width = 0.0;
            cin >> length >> width;
            p = new Rect(length, width);
            cout << "GetPerimeter=" << p->GetPerimeter() << endl;
            cout << "Area=" << p->GetArea() << endl;
            delete p;
            break;
        }
        default:
            cout << "input error" << endl;
            break;
    }

    return 0;
}