#include "head.h"
#include "LinkList.cpp"

#ifndef SetFunction
#define SetFunction

using namespace std;

// 两个链表简单相加
void SetUnion(LinkList &A, LinkList B)
{
    LNode *p;
    LNode *s;
    p = A;
    s = B;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (s->next != NULL)
    {
        s = s->next;
        LNode *q;
        q = (LNode *)malloc(sizeof(LNode));
        q->next = NULL;
        q->data = s->data;
        p->next = q;
        p = p->next;
    }
    return;
}

// 集合去重
void SetPrue(LinkList &A)
{
    if (A == NULL || A->next == NULL)
    {
        return;
    }

    LNode *p = A->next;
    while (p != NULL)
    {
        LNode *q = p;
        while (q->next != NULL)
        {
            if (q->next->data == p->data)
            {
                LNode *temp = q->next;
                q->next = q->next->next;
                free(temp);
            }
            else
            {
                q = q->next;
            }
        }
        p = p->next;
    }
    return;
}

#endif // SetFunction