#include "SQList.h"

#ifndef SQListFunction
#define SQListFunction

using namespace std;

typedef struct
{
    ElemType *elem;    // 指针
    int length;        // 目前长度
    int listSize;      // 总长度
    int incrementSize; // 每次增加的长度
} List;

// 初始化
void InitList(List &L)
{
    L.elem = new ElemType[LIST_INIT_SIZE];
    L.length = 0;
    L.listSize = LIST_INIT_SIZE;
    L.incrementSize = LIST_INCREMENT_SIZE;
}

// 顺序表扩容
bool ListExpan(List &L)
{
    List Le;
    Le.length = L.length;
    Le.listSize = L.listSize + LIST_INCREMENT_SIZE;
    Le.incrementSize = LIST_INCREMENT_SIZE;
    Le.elem = new ElemType[Le.listSize];

    for (int i = 0; i < L.length; i++)
    {
        Le.elem[i] = L.elem[i];
    }
    delete[] L.elem;
    L = Le;
    return true;
}

// 销毁顺序表
void DestroyList(List &L)
{
    delete[] L.elem;
    L.length = 0;
    L.listSize = 0;
}

// 清空顺序表
void ClearList(List &L)
{
    L.length = 0;
}

// 获取顺序表长度
int ListLength(List L)
{
    return L.length;
}

// 判断顺序表是否为空
bool ListEmpty(List L)
{
    return (L.length == 0);
}

// 获取顺序表中某个数据元素的内容
void GetElem(List L, int i, ElemType &e)
{
    if (i >= 1 && i <= L.length)
    {
        e = L.elem[i - 1];
    }
}

// 检索值为e的元素
int LocateElem(List L, ElemType e)
{
    int i;
    for (i = 0; i < L.length; ++i)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

// 获取cur_e的直接前驱元素
int PriorElem(List L, ElemType cur_e, ElemType &pre_e)
{
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial != 1)
    {
        return pre_e = L.elem[cur_e_serial - 2];
    }
    else
    {
        return 0;
    }
}

// 获取cur_e的直接后驱元素
int NextElem(List L, ElemType cur_e, ElemType &next_e)
{
    int cur_e_serial = LocateElem(L, cur_e);
    if (cur_e_serial != L.length)
    {
        return next_e = L.elem[cur_e_serial];
    }
    else
    {
        return 0;
    }
}

// 插入一个元素，成功返回true，失败返回false
bool ListInsert(List &L, ElemType i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length >= L.listSize)
    {
        if (!ListExpan(L))
        {
            return false;
        }
    }
    for (int j = L.length; j >= i; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return true;
}

// 删除顺序表第i个元素
bool ListInsertCreat(List &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    return true;
}

// 删除顺序表的第i个元素
bool ListDelete(List &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.elem[i - 1];
    for (int j = i; j < L.length; ++j)
    {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return true;
}

// 输出顺序表的每个元素
void ListTraverse(List L)
{
    for (int i = 0; i < L.length; ++i)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

#endif // SQListFunction
