#include "StackFunction.cpp"
#ifndef SolveFunction
#define SolveFunction

bool CheckBalancedBrackets(string str)
{
    SqStack S;
    InitStack(S);
    for (auto ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            Push(S, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (StackEmpty(S))
            {
                return false;
            }
            ElemType topElement;
            GetTop(S, topElement);
            if ((ch == ')' && topElement == '(') || (ch == ']' && topElement == '[') || (ch == '}' && topElement == '{'))
            {
                Pop(S, topElement);
            }
            else
            {
                return false;
            }
        }
        else
        {
            continue;
        }
    }
    return true;
}

bool CheckPalindrome(string str)
{
    SqStack S;
    InitStack(S);
    for (auto ch : str)
    {
        Push(S, ch);
    }
    for (auto ch : str)
    {
        if (StackEmpty(S))
        {
            return false;
        }
        ElemType topElement;
        Pop(S, topElement);
        if (topElement != ch)
        {
            return false;
        }
    }
    return StackEmpty(S);
}

int FindMax(vector<int> &values, int left, int right)
{
    if (right - left + 1 == 1)
    {
        return values[right];
    }
    if (right - left + 1 == 2)
    {
        return max(values[left], values[right]);
    }
    return max(FindMax(values, left, (right + left) / 2), FindMax(values, (right + left) / 2 + 1, right));
}

int FindMin(vector<int> &values, int left, int right)
{
    if (right - left + 1 == 1)
    {
        return values[right];
    }
    if (right - left + 1 == 2)
    {
        return min(values[left], values[right]);
    }
    return min(FindMin(values, left, (right + left) / 2), FindMin(values, (right + left) / 2 + 1, right));
}

#endif
