#include "head.h"

#ifndef LinkListFunction
#define LinkListFunction

using namespace std;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} LNode, *LinkList;

// 一些基础的函数，与第二次实验相同
//  初始化链表（头节点）
void InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->data = NULL;
    L->next = NULL;
}

// 计算链表长度
int ListLength(LinkList L)
{
    LNode *p;
    p = L->next;
    int cnt = 0;
    while (p != NULL)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

// 删除整个链表
void DestroyList(LinkList &L)
{
    LNode *p;
    while (L != NULL)
    {
        p = L->next;
        delete L;
        L = p;
    }
}

// 清除头节点以后的节点
void ClearList(LinkList &L)
{
    LNode *p;
    while (L->next != NULL)
    {
        p = L->next;
        L->next = p->next;
        delete p;
    }
}

// 头插法
void ListHeadInsert(LinkList &L, ElemType x)
{
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    if (p == NULL)
    {
        return;
    }
    p->data = x;
    p->next = L->next;
    L->next = p;

    return;
}

// 尾插法
void ListTailInsert(LinkList &L, ElemType x)
{
    LNode *s;
    LNode *p;
    p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }

    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    p->next = s;
    return;
}

LNode *FindFirstCommonNode(LinkList A, LinkList B)
{
    LNode *pA = A->next, *pB = B->next;
    int lenA = ListLength(A);
    int lenB = ListLength(B);

    if (lenA == 0 || lenB == 0)
    {
        return NULL;
    }

    // 长度对齐
    if (lenA > lenB)
    {
        int diff = lenA - lenB;
        while (diff--)
        {
            pA = pA->next;
        }
    }
    else if (lenA < lenB)
    {
        int diff = lenB - lenA;
        while (diff--)
        {
            pB = pB->next;
        }
    }

    // temp位于不同元素的下一个，时间复杂度为 O(n)
    LNode *ans = NULL;
    LNode *temp = pA;
    while (pA != NULL && pB != NULL)
    {
        if (pA->data == pB->data)
        {
            ans = temp;
        }
        else
        {
            temp = pA->next;
        }
        pA = pA->next;
        pB = pB->next;
    }

    return ans;
}

void LNodeMerge(LinkList &A, LinkList B)
{
    Lnode *p, *q;
}

// 输出链表的每个元素
void LNodeTraverse(LinkList L)
{
    LNode *p;
    ElemType e;
    p = L;
    while (p->next != NULL)
    {
        p = p->next;
        e = p->data;
        cout << e << " ";
    }
    cout << endl;
}

#endif // LinkListFunction