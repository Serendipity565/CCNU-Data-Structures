#include "head.h"

#ifndef LinkListFunction
#define LinkListFunction

using namespace std;

typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
} LNode, *LinkList;
// 这里的 *LinkList 相当于 typedef struct Lnode *LinkList;

// 初始化链表（头节点）
void InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;
    L->next = nullptr;
}

// 删除整个链表
void DestroyList(LinkList &L)
{
    LNode *p;
    while (L != NULL)
    {
        p = L->next;
        free(L);
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

// 判断链表是否为空
bool ListEmpty(LinkList L)
{
    if (L->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
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
    if (s == NULL)
    {
        return;
    }
    s->data = x;
    s->next = NULL;
    p->next = s;
    return;
}

// 查找第i个元素
bool GetElem(LinkList L, int i, ElemType &e)
{
    LNode *p = L->next;
    int count = 1;
    if (i < 1)
    {
        return false;
    }
    while (p != NULL && count < i)
    {
        p = p->next;
        count++;
    }
    if (count == i && p != NULL)
    {
        e = p->data;
        return true;
    }
    else
    {
        return false;
    }
}

// 查找第i个节点
LNode *GetNode(LinkList L, int i)
{
    LNode *p;
    p = L;
    int count = 0;
    while (p != NULL && count < i)
    {
        p = p->next;
        count++;
    }
    if (count == i && p != NULL)
    {
        return p;
    }
    else
    {
        p = NULL;
        return p;
    }
}

// 查找e第一次出现的位置
int LocateElem(LinkList L, ElemType e)
{
    LNode *p;
    p = L->next;
    int count = 1;
    while (p != NULL && p->data != e)
    {
        p = p->next;
        count++;
    }
    if (p == NULL)
    {
        return -1;
    }
    if (p->data == e)
    {
        return count;
    }
    return -1;
}

// 返回该节点的后i个元素
bool NextElem(LNode *p, int i, ElemType &e)
{
    if (p == NULL)
    {
        return false;
    }

    if (i == 0)
    {
        e = p->data;
        return true;
    }
    else if (i < 0)
    {
        return false;
    }

    int count = 0;
    while (p != NULL && count < i)
    {
        p = p->next;
        count++;
    }

    if (p != NULL)
    {
        e = p->data;
        return true;
    }
    else
    {
        return false;
    }
}

// 输出链表的每个元素
void LNodeTraverse(LinkList L)
{
    LNode *p = L->next;
    ElemType e;
    while (p != NULL)
    {
        e = p->data;
        cout << e << " ";
        p = p->next;
    }
    cout << endl;
}

#endif // LinkListFunction