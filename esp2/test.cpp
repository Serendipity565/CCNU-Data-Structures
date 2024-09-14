#include "head.h"
#include "LinkList.cpp"
#include "SetFunction.cpp"
using namespace std;

int main()
{
    LinkList L;
    // 初始化
    InitList(L);
    cout << "初始化时链表长度" << ListLength(L) << endl;

    // 头插法
    ListHeadInsert(L, 1);
    ListHeadInsert(L, 2);
    ListHeadInsert(L, 3);
    ListHeadInsert(L, 4);
    cout << "当前长度" << ListLength(L) << endl;
    // 输出链表
    LNodeTraverse(L);

    // 尾插法
    ListTailInsert(L, 5);
    ListTailInsert(L, 6);
    ListTailInsert(L, 7);
    ListTailInsert(L, 8);
    cout << "当前长度" << ListLength(L) << endl;
    // 输出链表
    LNodeTraverse(L);

    // 查找第3个元素
    cout << "第3个元素为:" << GetElem(L, 3) << endl;

    // 获取第5个节点
    LNode *n;
    ElemType e;
    n = GetNode(L, 5);
    // e = p->data;
    // cout << e << endl;
    //  输出第5个节点后2个的元素
    e = NextElem(n, 2);
    cout << "第5个节点后2个的元素:" << e << endl;

    // 查找元素第一次出现的位置
    cout << "元素1第一次出现的位置:" << LocateElem(L, 1) << endl;
    cout << "元素10第一次出现的位置:" << LocateElem(L, 10) << endl;

    // 清除头节点以后的节点
    ClearList(L);
    cout << "清除头节点以后的节点之后:" << endl;

    cout << "链表是否为空:" << ListEmpty(L) << endl;
    cout << "链表长度:" << ListLength(L) << endl;

    // 删除整个链表
    DestroyList(L);

    // 创建结合A
    LinkList A;
    InitList(A);
    ListHeadInsert(A, 1);
    ListHeadInsert(A, 2);
    ListHeadInsert(A, 3);
    ListHeadInsert(A, 4);
    cout << "集合A:";
    LNodeTraverse(A);

    // 创建结合B
    LinkList B;
    InitList(B);
    ListHeadInsert(B, 2);
    ListHeadInsert(B, 3);
    ListHeadInsert(B, 4);
    ListHeadInsert(B, 5);
    cout << "集合B:";
    LNodeTraverse(B);

    // A,B合并
    SetUnion(A, B);
    DestroyList(B);
    cout << "合并之后:";
    LNodeTraverse(A);

    // 集合提纯
    SetPrue(A);
    cout << "提纯之后:";
    LNodeTraverse(A);

    return 0;
}