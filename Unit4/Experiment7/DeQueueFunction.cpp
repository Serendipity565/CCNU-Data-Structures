#include "head.h"
#ifndef DeQueueFunction
#define DeQueueFunction

using namespace std;

// 定义链表节点结构体
typedef struct Node
{
    ElemType data;
    Node *next;
    Node *prev;
} Node;

typedef struct DouQueue
{
    Node *head;
    Node *tail;
    int len;
} DouQueue;

// 初始化队列
void InitQueue(DouQueue &Q)
{
    Q.head = nullptr;
    Q.tail = nullptr;
    Q.len = 0;
}

// 销毁队列
void DestroyQueue(DouQueue &Q)
{
    while (Q.head)
    {
        Node *temp = Q.head;
        Q.head = Q.head->next;
        delete temp;
    }
    Q.tail = nullptr;
    Q.len = 0;
}

// 清空队列
void ClearQueue(DouQueue &Q)
{
    while (Q.head)
    {
        Node *temp = Q.head;
        Q.head = Q.head->next;
        delete temp;
    }
    Q.tail = nullptr;
    Q.len = 0;
}

// 队列长度
int QueueLength(DouQueue Q)
{
    return Q.len;
}

// 队列是否为空
bool QueueEmpty(DouQueue Q)
{
    return Q.len == 0;
}

// 获取队头元素
bool GetHead(DouQueue Q, ElemType &e)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.head->data;
    return true;
}

// 获取队尾元素
bool GetTail(DouQueue Q, ElemType &e)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.tail->data;
    return true;
}

// 入队（头部）
bool EnQueueHead(DouQueue &Q, ElemType e)
{
    Node *newNode = new Node{e, nullptr, nullptr};
    if (QueueEmpty(Q))
    {
        Q.head = Q.tail = newNode;
    }
    else
    {
        newNode->next = Q.head;
        Q.head->prev = newNode;
        Q.head = newNode;
    }
    Q.len++;
    return true;
}

// 出队（头部）
bool DeQueueHead(DouQueue &Q, ElemType &e)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.head->data;
    Node *temp = Q.head;
    Q.head = Q.head->next;
    if (Q.head)
    {
        Q.head->prev = nullptr;
    }
    else
    {
        Q.tail = nullptr;
    }
    delete temp;
    Q.len--;
    return true;
}

// 入队（尾部）
bool EnQueueTail(DouQueue &Q, ElemType e)
{
    Node *newNode = new Node{e, nullptr, nullptr};
    if (QueueEmpty(Q))
    {
        Q.head = Q.tail = newNode;
    }
    else
    {
        newNode->prev = Q.tail;
        Q.tail->next = newNode;
        Q.tail = newNode;
    }
    Q.len++;
    return true;
}

// 出队（尾部）
bool DeQueueTail(DouQueue &Q, ElemType &e)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.tail->data;
    Node *temp = Q.tail;
    Q.tail = Q.tail->prev;
    if (Q.tail)
    {
        Q.tail->next = nullptr;
    }
    else
    {
        Q.head = nullptr;
    }
    delete temp;
    Q.len--;
    return true;
}

// 遍历队列
bool QueueTraverse(DouQueue Q)
{
    if (QueueEmpty(Q))
    {
        return false;
    }
    Node *temp = Q.head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return true;
}

#endif // DeQueueFunction
