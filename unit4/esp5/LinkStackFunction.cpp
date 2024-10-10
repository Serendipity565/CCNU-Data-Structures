#ifndef LinkStackFunction
#define LinkStackFunction

#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;

// 链表节点
struct Node
{
    ElemType data;
    Node *next;
};

// 链表栈
struct LinkedStack
{
    Node *top;  // 栈顶指针
    int length; // 栈长度
};

// 初始化栈
void InitStack(LinkedStack &S)
{
    S.top = nullptr;
    S.length = 0;
}

// 销毁栈
void DestroyStack(LinkedStack &S)
{
    while (S.top != nullptr)
    {
        Node *temp = S.top;
        S.top = S.top->next;
        delete temp;
    }
    S.length = 0;
}

// 清除栈元素
void ClearStack(LinkedStack &S)
{
    DestroyStack(S); // 清空栈
    S.top = nullptr;
    S.length = 0;
}

// 判断栈是否为空
bool StackEmpty(LinkedStack S)
{
    return S.top == nullptr;
}

// 获取栈长度
int StackLength(LinkedStack S)
{
    return S.length;
}

// 获取栈顶元素
bool GetTop(LinkedStack S, ElemType &e)
{
    if (S.top == nullptr)
    {
        return false;
    }
    e = S.top->data;
    return true;
}

// 栈顶放入元素
bool Push(LinkedStack &S, ElemType e)
{
    Node *newNode = new Node;
    newNode->data = e;
    newNode->next = S.top;
    S.top = newNode;
    S.length++;
    return true;
}

// 弹出栈顶元素
bool Pop(LinkedStack &S, ElemType &e)
{
    if (S.top == nullptr)
    {
        return false;
    }
    Node *temp = S.top;
    e = temp->data;
    S.top = S.top->next;
    delete temp;
    S.length--;
    return true;
}

// 输出栈内元素
bool StackTraverse(LinkedStack S)
{
    if (S.top == nullptr)
    {
        cout << "栈为空" << endl;
        return false;
    }
    Node *current = S.top;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return true;
}

#endif // LinkStackFunction