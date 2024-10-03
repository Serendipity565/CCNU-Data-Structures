#include "LinkList.cpp"
#include "head.h"
using namespace std;

int main()
{
    DuLinkList L;
    InitList(L);
    ReadStuMsg(L, "stumsg.txt");
    cout << "Befort QSort:" << endl;
    ShowStuMsg(L);
    QSort(L->next, L->prior);
    cout << "After QSort:" << endl;
    ShowStuMsg(L);
    DestroyList(L);
    return 0;
}