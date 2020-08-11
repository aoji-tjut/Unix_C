#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
using namespace std;

void PrintCategory(random_access_iterator_tag)
{
    cout << "random_access_iterator" << endl;
}

void PrintCategory(bidirectional_iterator_tag)
{
    cout << "bidirectional_iterator" << endl;
}

void PrintCategory(forward_iterator_tag)
{
    cout << "forward_iterator" << endl;
}

void PrintCategory(output_iterator_tag)
{
    cout << "output_iterator" << endl;
}

void PrintCategory(input_iterator_tag)
{
    cout << "input_iterator" << endl;
}

template<typename T>
void DisplayCategory(T it)
{
    //typename告诉编译器iterator_traits<T>::iterator_category是一个类型 cagy是一个变量
    typename iterator_traits<T>::iterator_category cagy;
    PrintCategory(cagy);

    //cout << typeid(it).name() << endl;
}

int main()
{
    //传入迭代器临时对象
    DisplayCategory(array<int, 10>::iterator());
    DisplayCategory(vector<int>::iterator());
    DisplayCategory(deque<int>::iterator());
    DisplayCategory(list<int>::iterator());
    DisplayCategory(forward_list<int>::iterator());
    cout << endl;

    DisplayCategory(set<int>::iterator());
    DisplayCategory(map<int, int>::iterator());
    DisplayCategory(multiset<int>::iterator());
    DisplayCategory(multimap<int, int>::iterator());
    cout << endl;

    DisplayCategory(unordered_set<int>::iterator());
    DisplayCategory(unordered_map<int, int>::iterator());
    DisplayCategory(unordered_multiset<int>::iterator());
    DisplayCategory(unordered_multimap<int, int>::iterator());
    cout << endl;

    DisplayCategory(istream_iterator<int>());
    DisplayCategory(ostream_iterator<int>(cout, ""));

    return 0;
}