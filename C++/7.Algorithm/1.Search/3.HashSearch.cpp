#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define HASHSIZE 19
int conflict = 0;

//哈希函数返回地址
int HashAddress(int value)
{
    return value % HASHSIZE;
}

//插入哈希表
void InsertHashTable(vector<int>& h, int value)
{
    int addr = HashAddress(value);

    //线性探测解决冲突
    while(h[addr] != -1)
    {
        addr = (addr + 1) % HASHSIZE;
        conflict++;
    }

    h[addr] = value;
}

int HashSearch(vector<int>& v, int n, int value)
{
    vector<int> hash_table(HASHSIZE);

    //初始化哈希表
    for(int& i : hash_table)
    {
        i = -1;
    }

    //v插入hash_table
    for(int i : v)
    {
        InsertHashTable(hash_table, i);
    }

    //打印hash_table
    for(int i : hash_table)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "conflict=" << ::conflict << endl;

    //查找
    int addr_init = HashAddress(value);
    int addr = addr_init;
    while(hash_table[addr] != value)
    {
        addr = (addr + 1) % HASHSIZE;

        //若查找值为-1或查找到初始地址则查找失败
        if(hash_table[addr] == -1 || addr == addr_init)
        {
            return -1;
        }
    }

    return addr;
}

int main()
{
    srand(time(nullptr));

    vector<int> v(10);
    for(int& i : v)
    {
        i = rand() % 100;
        cout << i << " ";
    }
    cout << endl;

    int value = v[rand() % 10];
    int pos = HashSearch(v, v.size(), value);

    cout << "value=" << value << endl;
    cout << "pos=" << pos << endl;

    return 0;
}