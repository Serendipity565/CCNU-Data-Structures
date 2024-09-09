#include "SQList.h"
#include "SQListFunction.cpp"
#include "SetFunction.cpp"

int main()
{
    List L;
    InitList(L);
    // L.data.resize(5);
    ListInsert(L, 1, 23);
    ListInsert(L, 2, 56);
    ListInsert(L, 3, 89);
    ListInsert(L, 4, 76);
    ListInsert(L, 5, 18);
    // ListTraverse(L);
    int i = 3, x = 56, y = 88, e = 0;
    cout << ListLength(L) << endl;
    GetElem(L, i, e);
    cout << e << endl;
    PriorElem(L, x, e);
    cout << e << endl;
    NextElem(L, x, e);
    cout << e << endl;
    cout << LocateElem(L, x) << endl;
    ListInsert(L, i, y);
    ListTraverse(L);
    ListDelete(L, i + 1, e);
    ListTraverse(L);
    cout << e << endl;
    List a, b;
    InitList(a);
    InitList(b);
    ListInsert(a, 1, 1);
    ListInsert(a, 2, 2);
    ListInsert(a, 3, 3);
    ListInsert(a, 4, 4);
    ListInsert(a, 5, 5);
    ListInsert(b, 1, 4);
    ListInsert(b, 2, 5);
    ListInsert(b, 3, 6);
    ListInsert(b, 4, 7);
    ListInsert(b, 5, 8);
    cout << "a: ";
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
    cout << "a+b(With B): ";
    SetUnion(a, b);
    // cout << "a+b(Without B): ";
    // unionListWithoutB(a, b);
    ListTraverse(a);
    cout << "b: ";
    ListTraverse(b);
    return 0;
}