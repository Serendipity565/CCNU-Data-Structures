#include "head.h"

#ifndef LinkListFunction
#define LinkListFunction

using namespace std;

struct Student
{
    string no;
    string name;
    int score;
    int time;
};

struct DuLNode
{
    Student stu;
    int i;
    DuLNode *prior;
    DuLNode *next;
};

typedef DuLNode *DuLinkList;

// 初始化
void InitList(DuLinkList &L)
{
    L = new DuLNode;
    if (L == NULL)
    {
        cerr << "Memory allocation failed" << endl;
    }
    L->prior = L;
    L->next = L;
    L->i = 0;
    return;
}

// 清空链表
void ClearList(DuLinkList &L)
{
    DuLNode *p = L->next;
    while (p != L)
    {
        DuLNode *q = p->next;
        delete p;
        p = q;
    }
    L->prior = L;
    L->next = L;
    L->i = 0;
}

// 销毁链表
void DestroyList(DuLinkList &L)
{
    DuLNode *p = L->next;
    while (p != L)
    {
        DuLNode *q = p->next;
        delete p;
        p = q;
    }
    delete L;
    L = nullptr;
}

// 插入节点
void InsertAfter(DuLinkList &L, DuLNode *p, Student stu)
{
    DuLNode *s = new DuLNode;
    s->stu = stu;

    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
    p->i++;
}

// 读取文件
void ReadStuMsg(DuLinkList &L, const char *filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cerr << "File could not be opened!" << endl;
        return;
    }
    Student stu;
    while (infile >> stu.no >> stu.name >> stu.score >> stu.time)
    {
        InsertAfter(L, L->prior, stu);
    }
    infile.close();
}

DuLNode *Partition(DuLNode *low, DuLNode *high)
{
    Student pivot = low->stu;
    while (low != high)
    {
        while (low != high && (high->stu.score < pivot.score || (high->stu.score == pivot.score && high->stu.time > pivot.time)))
        {
            high = high->prior;
        }
        low->stu = high->stu;
        while (low != high && (low->stu.score > pivot.score || (low->stu.score == pivot.score && low->stu.time < pivot.time)))
        {
            low = low->next;
        }
        high->stu = low->stu;
    }
    low->stu = pivot;
    return low;
}

// 快排
void QSort(DuLNode *low, DuLNode *high)
{
    if (low != high && low->prior != high)
    {
        DuLNode *pivot = Partition(low, high);
        QSort(low, pivot->prior);
        QSort(pivot->next, high);
    }
}

// 输出
void ShowStuMsg(DuLinkList L)
{
    DuLNode *p = L->next;
    while (p != L)
    {
        cout << p->stu.no << " " << p->stu.name << " " << p->stu.score << " " << p->stu.time << endl;
        p = p->next;
    }
}
#endif