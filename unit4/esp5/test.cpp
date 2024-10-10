#include <bits/stdc++.h>
#include "StackFunction.cpp"

using namespace std;

bool check(vector<int> &pushSeq, vector<int> &popSeq)
{
    SqStack S;
    InitStack(S);
    int j = 0;

    for (int i = 0; i < pushSeq.size(); i++)
    {
        Push(S, pushSeq[i]);
        cout << pushSeq[i] << "入" << endl;
        while (!StackEmpty(S) && S.elem[S.top] == popSeq[j])
        {
            int temp;
            Pop(S, temp);
            cout << popSeq[j] << "出" << endl;
            j++;
        }
    }

    DestroyStack(S);

    return j == popSeq.size();
}

int main()
{
    vector<int> pushSeq1 = {1, 2, 3};
    vector<int> popSeq1 = {2, 1, 3};
    vector<int> pushSeq2 = {1, 2, 3};
    vector<int> popSeq2 = {3, 1, 2};

    cout << "案例1:" << endl;
    if (check(pushSeq1, popSeq1))
    {
        cout << "出入栈的顺序成立" << endl;
    }
    else
    {
        cout << "出入栈的顺序不成立" << endl;
    }

    cout << "案例2:" << endl;
    if (check(pushSeq2, popSeq2))
    {
        cout << "出入栈的顺序成立" << endl;
    }
    else
    {
        cout << "出入栈的顺序不成立" << endl;
    }

    return 0;
}
