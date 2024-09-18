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
    ListTailInsert(A, 4);
    cout << "链表A:";
    LNodeTraverse(A);

    // 创建链表B
    LinkList B;
    InitList(B);
    ListTailInsert(B, 5);
    ListTailInsert(B, 2);
    ListTailInsert(B, 3);
    ListTailInsert(B, 4);
    cout << "链表B:";
    LNodeTraverse(B);

    // 查找第一个公共点
    LNode *p = FindFirstCommonNode(A, B);
    if (p != NULL)
    {
        ElemType e = p->data;
        cout << "第一个公共元素为:" << e << endl;
    }
    else
    {
        cout << "没有公共元素" << endl;
    }

    // 单调递增合并
    ListTailInsert(B, -5);
    ListTailInsert(B, -2);
    LNodeMerge(A, B);
    LNodeTraverse(A);

    return 0;
}