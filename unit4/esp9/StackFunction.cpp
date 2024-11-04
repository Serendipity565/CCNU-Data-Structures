#include "head.h"

#ifndef StackFunction
#define StackFunction

using namespace std;

typedef struct
{
    ElemType *elem;
    int top;
    int stacksize;
    int incrementsize;
} SqStack;

// 初始化
void InitStack(SqStack &S)
{
    S.elem = new ElemType[STACK_INIT_SIZE];
    S.top = -1;
    S.stacksize = STACK_INIT_SIZE;
    S.incrementsize = STACKINCREMENT;
    return;
}

// 销毁栈
void DestroyStack(SqStack &S)
{
    if (!S.elem)
    {
        cout << "warning: 栈未初始化" << endl;
        return;
    }
    delete[] S.elem;  // 释放数组内存
    S.elem = nullptr; // 防止悬空指针
    S.top = -1;
    S.stacksize = 0;
    S.incrementsize = 0;
    return;
}

// 清除栈元素
void ClearStack(SqStack &S)
{
    if (!S.elem)
    {
        cout << "warning: 栈未初始化" << endl;
        return;
    }
    S.top = -1;
    return;
}

// 判断栈是否为空
bool StackEmpty(SqStack S)
{
    if (!S.elem)
    {
        cout << "warning: 栈未初始化" << endl;
        return true;
    }
    return S.top == -1;
}

// 获取栈长度
int StackLength(SqStack S)
{
    if (!S.elem)
    {
        cout << "error: 栈未初始化" << endl;
        return -1;
    }
    return S.top + 1;
}

// 获取栈顶元素
bool GetTop(SqStack S, ElemType &e)
{
    if (!S.elem)
    {
        cout << "error: 栈未初始化" << endl;
        return false;
    }
    if (S.top == -1)
    {
        cout << "error: 栈为空" << endl;
        return false;
    }
    e = S.elem[S.top];
    return true;
}

// 栈顶放入元素
bool Push(SqStack &S, ElemType e)
{
    if (!S.elem)
    {
        cout << "error: 栈未初始化" << endl;
        return false;
    }
    // 检查栈是否满
    // if (S.top == S.stacksize - 1)
    // {
    //     // 动态扩展栈的大小
    //     ElemType *newElem = new ElemType[S.stacksize + S.incrementsize];
    //     if (!newElem)
    //     {
    //         cout << "error: 内存分配失败" << endl;
    //         return false;
    //     }
    //     for (int i = 0; i <= S.top; ++i)
    //     {
    //         newElem[i] = S.elem[i];
    //     }
    //     delete[] S.elem;
    //     S.elem = newElem;
    //     S.stacksize += S.incrementsize;
    // }
    if (S.top == S.stacksize - 1)
    {
        cout << "error: 栈已满" << endl;
        return false;
    }
    S.elem[++S.top] = e;
    return true;
}

// 弹出栈顶元素
bool Pop(SqStack &S, ElemType &e)
{
    if (!S.elem)
    {
        cout << "error: 栈未初始化" << endl;
        return false;
    }
    if (S.top == -1)
    {
        cout << "error: 栈为空" << endl;
        return false;
    }
    e = S.elem[S.top--];
    return true;
}

// 输出栈内元素
bool StackTraverse(SqStack S)
{
    if (!S.elem)
    {
        cout << "error: 栈未初始化" << endl;
        return false;
    }
    if (S.top == -1)
    {
        cout << endl;
        // cout << "栈为空" << endl;
        return false;
    }
    for (int i = 0; i <= S.top; ++i)
    {
        cout << S.elem[i] << " ";
    }
    cout << endl;
    return true;
}

#endif // StackFunction