#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>     //istream_iterator适配器
using namespace std;

int main()
{
    int num1 = 0, num2 = 0;
    istream_iterator<int> EOS;  //end-of-stream iterator
    cout << "input 2 numbers:" << endl;
    istream_iterator<int> num_in_it(cin);   //输入流迭代器 此时开始读入

    if(num_in_it != EOS)
    {
        num1 = *num_in_it;
    }

    num_in_it++;
    if(num_in_it != EOS)
    {
        num2 = *num_in_it;
    }

    cout << "num1 + num2 = " << num1 + num2 << endl;
    cout << endl;

    vector<int> v;
    istream_iterator<int> eos;
    cout << "input vector:" << endl;
    istream_iterator<int> v_in_it(cin);

    copy(v_in_it, eos, inserter(v, v.begin()));     //eos是Ctrl+d

    for(int i:v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}