#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct Node
{
    char data;
    Node* left_child;
    Node* right_child;
} Node, * Tree;

void BuildTree(Tree& T)
{
    char c;
    cin.get(c);

    if(c == '-')
    {
        T = nullptr;
    }
    else
    {
        T = new Node();
        if(!T)
        {
            cout << "Overflow" << endl;
            exit(-1);
        }

        T->data = c;
        BuildTree(T->left_child);
        BuildTree(T->right_child);
    }
}

void Visit(char c)
{
    cout << c << "";
}

void PreOrder(Tree T)
{
    if(T)
    {
        Visit(T->data);
        PreOrder(T->left_child);
        PreOrder(T->right_child);
    }
}

void InOrder(Tree T)
{
    if(T)
    {
        InOrder(T->left_child);
        Visit(T->data);
        InOrder(T->right_child);
    }
}

void PostOrder(Tree T)
{
    if(T)
    {
        PostOrder(T->left_child);
        PostOrder(T->right_child);
        Visit(T->data);
    }
}

void InOrderNoRecursive(Tree T)
{
    stack<Tree> s;
    Tree p = T;

    //树不为空或栈不为空
    while(p || !s.empty())
    {
        if(p)                           //树不为空
        {
            s.push(p);                  //当前节点进栈
            p = p->left_child;          //继续寻找左节点
        }
        else                            //树为空栈不为空
        {
            Visit(s.top()->data);       //访问栈顶节点
            p = s.top()->right_child;   //寻找栈顶节点右节点
            s.pop();                    //栈顶节点出栈
        }
    }
}

void LevelOrder(Tree T)
{
    queue<Tree> q;
    Tree p = T;

    if(p)
    {
        q.push(p);
    }

    while(!q.empty())
    {
        Visit(q.front()->data);
        p = q.front();
        q.pop();

        if(p->left_child)
        {
            q.push(p->left_child);
        }

        if(p->right_child)
        {
            q.push(p->right_child);
        }
    }
}

void DestoryTree(Tree& T)
{
    if(T)
    {
        DestoryTree(T->left_child);
        DestoryTree(T->right_child);
        Visit(T->data);
        delete T;
    }
}

int main()
{
    Tree T;

    cout << "BuildTree：";
    BuildTree(T);
    cout << endl;

    cout << "PreOrder：";
    PreOrder(T);
    cout << endl;

    cout << "InOrder：";
    InOrder(T);
    cout << endl;

    cout << "PostOrder：";
    PostOrder(T);
    cout << endl;

    cout << "InOrderNoRecursive：";
    InOrderNoRecursive(T);
    cout << endl;

    cout << "LevelOrder：";
    LevelOrder(T);
    cout << endl;

    cout << "DestoryTree：";
    DestoryTree(T);
    cout << endl;

    return 0;
}