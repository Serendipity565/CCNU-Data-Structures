#include "head.h"

#ifndef QueueFunction
#define QueueFunction

using namespace std;

typedef struct
{
    ElemType *elem;
    int front;
    int rear;
    int len;
    int queuesize;
    int incrementsize;
} SeQueue;

// 初始化队列
void InitQueue(SeQueue &Q)
{
    Q.elem = new ElemType[QUEUE_INIT_SIZE];
    Q.front = 0;
    Q.rear = 0;
    Q.len = 0;
    Q.queuesize = QUEUE_INIT_SIZE;
    Q.incrementsize = QUEUEINCREMENT;
}

// 销毁队列
void DestroyQueue(SeQueue &Q)
{
    delete[] Q.elem;
    Q.elem = nullptr;
    Q.front = 0;
    Q.rear = 0;
    Q.len = 0;
    Q.queuesize = 0;
    Q.incrementsize = 0;
}

// 清空队列
void ClearQueue(SeQueue &Q)
{
    Q.front = 0;
    Q.rear = 0;
    Q.len = 0;
}

// 队列长度
int QueueLength(SeQueue Q)
{
    if (Q.elem == nullptr)
    {
        cerr << "队列未初始化" << endl;
        return -1;
    }
    return Q.len;
}

// 队列是否为空
bool QueueEmpty(SeQueue Q)
{
    if (Q.elem == nullptr)
    {
        cerr << "队列未初始化" << endl;
        return false;
    }
    return Q.len == 0;
}

// 获取队头元素
bool GetHead(SeQueue Q, ElemType &e)
{
    if (Q.elem == nullptr)
    {
        cerr << "队列未初始化" << endl;
        return false;
    }
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.elem[Q.front];
    return true;
}

// 入队
bool EnQueue(SeQueue &Q, ElemType e)
{
    // 检查队列是否已满
    // if ((Q.rear + 1) % Q.queuesize == Q.front)
    // {
    //     ElemType *newElem = new ElemType[Q.queuesize + Q.incrementsize];
    //     if (newElem == nullptr)
    //     {
    //         cerr << "扩容内存分配失败" << endl;
    //         return false;
    //     }
    //     int i = 0;
    //     for (int j = Q.front; j != Q.rear; j = (j + 1) % Q.queuesize)
    //     {
    //         newElem[i++] = Q.elem[j];
    //     }
    //     delete[] Q.elem;
    //     Q.elem = newElem;
    //     Q.front = 0;
    //     Q.rear = i;
    //     Q.queuesize += Q.incrementsize;
    // }
    if ((Q.rear + 1) % Q.queuesize == Q.front)
    {
        cout << "error: 队列已满" << endl;
        return false;
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.queuesize;
    Q.len++;
    return true;
}

// 出队
bool DeQueue(SeQueue &Q, ElemType &e)
{
    if (Q.elem == nullptr)
    {
        cerr << "队列未初始化" << endl;
        return false;
    }
    if (QueueEmpty(Q))
    {
        return false;
    }
    e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % Q.queuesize;
    Q.len--;
    return true;
}

// 遍历队列
bool QueueTraverse(SeQueue Q)
{
    if (Q.elem == nullptr)
    {
        cerr << "队列未初始化" << endl;
        return false;
    }
    if (QueueEmpty(Q))
    {
        cout << endl;
        return false;
    }
    int i = Q.front;
    while (i != Q.rear)
    {
        cout << Q.elem[i] << " ";
        i = (i + 1) % Q.queuesize;
    }
    cout << endl;
    return true;
}

#endif // QueueFunction