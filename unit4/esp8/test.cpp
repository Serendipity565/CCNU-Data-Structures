#include <bits/stdc++.h>
using namespace std;

// 是否为运算符
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 是否为数字
bool isOperand(char c)
{
    return isdigit(c);
}

// 运算符优先级
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 计算
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

// 检查表达式是否合法
bool isValidExpression(const string &exp)
{
    stack<char> s;
    bool flag = true; // 检查最后一个运算符后是否有数字

    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (c == ' ')
            continue;
        if (c == '(')
        {
            s.push(c);
            flag = true;
        }
        else if (c == ')')
        {
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
            flag = false;
        }
        else if (isOperator(c))
        {
            if (flag)
                return false;
            flag = true; // 连续两个运算符是不合法的
        }
        else if (isOperand(c))
        {
            flag = false;
        }
        else
        {
            return false; // 有非法字符
        }
    }
    if (flag)
        return false; // 如果表达式以运算符结尾，不合法
    return s.empty();
}

// 计算函数
int evaluateInfix(const string &exp)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == ' ')
            continue;
        if (exp[i] == '(')
        {
            ops.push(exp[i]);
        }
        else if (isdigit(exp[i])) // 将数字压入values栈
        {
            int val = 0;
            while (i < exp.length() && isdigit(exp[i]))
            {
                val = (val * 10) + (exp[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }
        else if (exp[i] == ')') // 遇到右括号，优先计算括号内的表达式
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.pop();
        }
        else if (isOperator(exp[i])) // 遇到运算符，计算
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(exp[i])) // 考虑乘除的优先级大于加减
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(exp[i]);
        }
    }
    while (!ops.empty())
    {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }
    return values.top();
}

int main()
{
    string exp;
    cout << "Enter an infix expression: ";
    getline(cin, exp);
    if (isValidExpression(exp))
        cout << "The value of the expression is: " << evaluateInfix(exp) << endl;
    else
        cout << "Invalid expression" << endl;
    return 0;
}