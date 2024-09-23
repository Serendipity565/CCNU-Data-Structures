#include "LinkList.cpp"
#include "head.h"
using namespace std;

int main()
{
    // 创建链表A
    LinkList A;
    InitList(A);
    ListTailInsert(A, 1);
    ListTailInsert(A, 2);
    ListTailInsert(A, 3);

    // 创建链表B
    LinkList B;
    InitList(B);
    ListTailInsert(B, 4);
    ListTailInsert(B, 5);

    // // 创建公共链表
    // LinkList C;
    // InitList(C);
    // ListTailInsert(C, 6);
    // ListTailInsert(C, 7);
    // ListTailInsert(C, 8);
    // LNode *p = A->next;
    // while (p->next != NULL)
    // {
    //     p = p->next;
    // }
    // p->next = C->next;

    // p = B->next;
    // while (p->next != NULL)
    // {
    //     p = p->next;
    // }
    // p->next = C->next;

    // 创建公共部分
    LNode *el1, *el2 = new LNode;
    el2->data = 7;
    el2->next = NULL;
    el1->data = 6;
    el1->next = el2;

    LNode *p = GetNode(A, ListLength(A));
    LNode *q = GetNode(B, ListLength(B));
    p->next = el1;
    q->next = el1;

    cout << "链表A:";
    LNodeTraverse(A);
    cout << "链表B:";
    LNodeTraverse(B);

    // 查找第一个公共点
    p = FindFirstCommonNode(A, B);
    if (p != NULL)
    {
        ElemType e = p->data;
        cout << "第一个公共元素为:" << e << endl;
    }
    else
    {
        cout << "没有公共元素" << endl;
    }

    // 创建链表D
    LinkList D;
    InitList(D);
    ListTailInsert(D, 1);
    ListTailInsert(D, 2);
    ListTailInsert(D, 3);
    ListTailInsert(D, 4);
    cout << "链表D:";
    LNodeTraverse(D);

    // 创建链表E
    LinkList E;
    InitList(E);
    ListTailInsert(E, 3);
    ListTailInsert(E, 4);
    ListTailInsert(E, 0);
    ListTailInsert(E, -5);
    ListTailInsert(E, -2);
    // 对E进行排序
    ListSort(E);
    cout << "E排序后";
    LNodeTraverse(E);
    // 单调递增合并
    LNodeMerge(D, E);
    LNodeTraverse(D);

    return 0;
}