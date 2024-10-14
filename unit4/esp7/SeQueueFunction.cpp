#include "head.h"

#ifndef QueueFunction
#define QueueFunction

using namespace std;

typedef struct
{
    ElemType *elem;
    int front;
    int rear;
    int queuesize;
    int incrementsize;
} SeQueue;

void InitQueue(SeQueue &Q)
{
}

void DestroyQueue()
{
}

void ClearQueue()
{
}

int QueueLength()
{
}

bool QueueEmpty()
{
}

bool GetHead()
{
}

bool EnQueue()
{
}

bool DeQueue()
{
}

bool QueueTraverse()
{
}

#endif // QueueFunction