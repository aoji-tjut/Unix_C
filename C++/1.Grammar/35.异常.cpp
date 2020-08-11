#include <iostream>
using namespace std;

int main()
{
    try     //检测异常
    {
        int i = 1;

        while(true)
        {
            if(i == 5)
            {
                throw i;    //抛出异常 终止进程
            }
            cout << i << endl;
            i++;
        }
    }
    catch(int error)    //捕捉异常 可以重载
    {
        cout << "异常值：" << error << endl;
    }
    catch(...)          //可以捕获任何类型的异常
    {
        cout << "..." << endl;
    }

    return 0;
}