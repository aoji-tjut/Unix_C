#include <iostream>
#include <memory>   //栈区指针 自动释放
using namespace std;

class A
{
public:
    A(int a)
    {
        cout << this << " 构造函数" << endl;
        this->a = a;
    }

    ~A()
    {
        cout << this << " 析构函数" << endl;
    }

    int a;
};

//独有指针
void UniquePtr()
{
    unique_ptr<A> p(new A(10));     //一个对象只能由一个指针指向
    cout << p << " " << p->a << endl;
    cout << endl;

    unique_ptr<A> q = move(p);      //p所有权转移给q
    if(!p)
    {
        cout << "p指针为空 " << p << endl;
    }
    cout << q << " " << q->a << endl;
    cout << endl;

    q = make_unique<A>(20);         //先重新构造q 后析构之前的q
    cout << q << " " << q->a << endl;
    cout << endl;
}

//共享指针
void SharedPtr()
{
    shared_ptr<A> p(new A(10));
    cout << p << " " << p->a << endl;
    cout << "引用计数：" << p.use_count() << endl;
    cout << endl;

    shared_ptr<A>& q = p;
    cout << q << " " << q->a << endl;
    cout << "引用计数：" << q.use_count() << endl;
    cout << endl;

    shared_ptr<A> r = q;
    cout << r << " " << r->a << endl;
    cout << "引用计数：" << r.use_count() << endl;
    cout << endl;
}

int main()
{
    //智能指针就是一个类 当超出了类的作用域时 类会自动调用析构函数 析构函数会自动释放资源

    //unique_ptr实现独占式拥有或严格拥有概念 保证同一时间内只有一个智能指针可以指向该对象
    UniquePtr();
    cout << "------------------------------------------" << endl;
    cout << endl;

    //shared_ptr实现共享式拥有概念 多个智能指针可以指向相同对象 该对象和其相关资源会在"最后一个引用被销毁"时候释放
    SharedPtr();

    return 0;
}