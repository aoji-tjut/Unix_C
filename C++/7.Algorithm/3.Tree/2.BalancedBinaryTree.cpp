#include <iostream>
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
        T = new Node;
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
    else
    {
        cout << '-';
    }
}

Tree& FindLetfest(Tree& T)
{
    if(T->left_child)
    {
        return FindLetfest(T->left_child);
    }

    return T;
}

Tree& FindRightest(Tree& T)
{
    if(T->right_child)
    {
        return FindRightest(T->right_child);
    }

    return T;
}

void TurnLeft(Tree& T)
{
    Tree old_root = T;
    T = old_root->right_child;
    old_root->right_child = nullptr;

    //寻找最左节点
    FindLetfest(T)->left_child = old_root;
}

void TurnRight(Tree& T)
{
    Tree old_root = T;
    T = old_root->left_child;
    old_root->left_child = nullptr;

    //寻找最右节点
    FindRightest(T)->right_child = old_root;
}

int Depth(Tree& T)
{
    if(!T)
    {
        return 0;
    }

    int l = Depth(T->left_child);
    int r = Depth(T->right_child);

    return max(l, r) + 1;
}

void Balance(Tree& T)
{
    if(!T)
    {
        return;
    }

    int sub;
    while(true)
    {
        sub = Depth(T->left_child) - Depth(T->right_child);

        if(sub < -1)
        {
            TurnLeft(T);
        }
        else if(sub > 1)
        {
            TurnRight(T);
        }
        else
        {
            break;
        }
    }

    Balance(T->left_child);
    Balance(T->right_child);
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
    else
    {
        cout << '-';
    }
}

int main()
{
    Tree T;     //1246---5--3--

    cout << "BuildTree：";
    BuildTree(T);
    cout << endl;

    cout << "Before Balance:" << endl;
    PreOrder(T);
    cout << endl << endl;

    Balance(T);

    cout << "After Balance:" << endl;
    PreOrder(T);
    cout << endl << endl;

    cout << "DestoryTree：" << endl;
    DestoryTree(T);
    cout << endl;

    return 0;
}