#include "SQList.h"
#include "SQListFunction.cpp"

#ifndef SetFunction
#define SetFunction

using namespace std;

bool SetUnion(List &A, List B)
{
    for (int i = 0; i < ListLength(B); i++)
    {
        if (LocateElem(A, B.elem[i]) == 0)
        {
            if (!ListInsert(A, ListLength(A) + 1, B.elem[i]))
            {
                return false;
            }
        }
    }
    return true;
}

#endif // SetFunction