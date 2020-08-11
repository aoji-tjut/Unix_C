#include <iostream>
#include <string>
using namespace std;

//初始化
void Init()
{
    string s1("abc");
    cout << s1 << endl;

    const char* str = "abc";
    string s2(str);
    cout << s2 << endl;

    string s3(s2);      //拷贝构造
    cout << s3 << endl;

    string s4(3, 'a');  //3个a
    cout << s4 << endl;
}

//赋值
void Assign()
{
    string s1;
    s1 = "abc";
    cout << s1 << endl;

    string s2;
    s2 = s1;
    cout << s2 << endl;

    string s3;
    s3.assign("abc");
    cout << s3 << endl;

    string s4;
    s4.assign("abc", 2);    //将前2个字符赋值
    cout << s4 << endl;

    string s5;
    s5.assign(s4);
    cout << s5 << endl;

    string s6;
    s6.assign(3, 'a');      //3个a赋值
    cout << s6 << endl;
}

//追加
void Append()
{
    string s("abc");
    cout << s << endl;

    s += "def";
    cout << s << endl;

    s.append("ghi");
    cout << s << endl;

    s.append("jklmn", 3);       //追加前3个字符
    cout << s << endl;

    s.append("mnopq", 2, 3);    //从第2个位置开始追加3个字符
    cout << s << endl;
}

//查找
void Find()
{
    string s("abcabc");

    int pos1 = s.find("bc", 0);     //从左向右 0位置开始查找是否有"bc" 有返回下标 无返回-1
    cout << pos1 << endl;

    int pos2 = s.rfind("bc", 5);    //从右向左 0位置开始查找是否有"bc" 有返回下标 无返回-1
    cout << pos2 << endl;
}

//替换
void Replace()
{
    string s("00011000");

    s.replace(3, 2, "222");     //从3位置起2个字符替换为"222"
    cout << s << endl;
}

//比较
void Compare()
{
    string s1("abc");
    string s2("ABC");

    int result = s1.compare(s2);    //比较ASCII 相同返回0 等长不同值返回ASCII差值 不等长不同值返回1/-1
    cout << result << endl;
}

//读写
void At()
{
    string s("000");

    for(int i = 0; i < s.size(); i++)
    {
        s[i] = '1';
        cout << s[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < s.size(); i++)
    {
        s.at(i) = '2';
        cout << s.at(i) << " ";
    }
    cout << endl;
}

//插入删除
void InsertErase()
{
    string s("0000");

    s.insert(2, "111");     //在2位置插入"111"
    cout << s << endl;

    s.erase(2, 3);          //从2位置删除3个字符
    cout << s << endl;
}

//子串
void Substr()
{
    string s("abcdefg");
    string sub;

    sub = s.substr(0, 3);   //从0开始截取3个字符
    cout << sub << endl;

    //截取用户名
    string mail("aoji@qq.com");
    int pos = mail.find('@');
    string user_name = mail.substr(0, pos);
    cout << user_name << endl;
}

int main()
{
    Init();
    Assign();
    Append();
    Find();
    Replace();
    Compare();
    At();
    InsertErase();
    Substr();

    return 0;
}