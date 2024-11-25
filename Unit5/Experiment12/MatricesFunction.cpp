#ifndef MatricesFunction
#define MatricesFunction

#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 100;
typedef int Elemtype;

typedef struct
{
    int i; // 行号
    int j; // 列号
    Elemtype e;
} Triple;

typedef struct
{
    Triple data[MAXSIZE + 1];
    int mu; // 行数
    int nu; // 列数
    int tu; // 非零元素总数
} TSMatrix;

// 初始化
void InitMatrix(TSMatrix &matrix, int rows, int cols)
{
    matrix.mu = rows;
    matrix.nu = cols;
    matrix.tu = 0;
}

// 赋值
void AssignValue(TSMatrix &matrix, int row, int col, Elemtype value)
{
    if (matrix.tu >= MAXSIZE)
    {
        cout << "Matrix exceeds maximum allowed size!" << endl;
        return;
    }

    if (row <= 0 || row > matrix.mu || col <= 0 || col > matrix.nu)
    {
        cout << "The index is out of the matrix and the insert fails" << endl;
        return;
    }

    if (value == 0)
    {
        return;
    }

    // 遍历查找插入位置或更新点
    int pos = 1;
    while (pos <= matrix.tu)
    {
        if (matrix.data[pos].i == row && matrix.data[pos].j > col)
        {
            cout << "The element already exists in this position, and the insertion fails" << endl;
            return;
        }
        if (matrix.data[pos].i > row || (matrix.data[pos].i == row && matrix.data[pos].j > col))
        {
            break;
        }
        pos++;
    }

    for (int i = matrix.tu; i >= pos; i--)
    {
        matrix.data[i + 1] = matrix.data[i];
    }
    matrix.data[pos].i = row;
    matrix.data[pos].j = col;
    matrix.data[pos].e = value;
    matrix.tu++;
}

// 相加
void AddMatrices(const TSMatrix &A, const TSMatrix &B, TSMatrix &C)
{
    if (A.mu != B.mu || A.nu != B.nu)
    {
        cout << "Matrices sizes do not match!" << endl;
        return;
    }

    C.mu = A.mu;
    C.nu = A.nu;
    C.tu = 0;

    int a = 1, b = 1, c = 1;
    while (a <= A.tu && b <= B.tu)
    {
        if (A.data[a].i == B.data[b].i && A.data[a].j == B.data[b].j)
        {
            C.data[c] = A.data[a];
            C.data[c].e += B.data[b].e;
            if (C.data[c].e == 0)
            {
                c--;
            }
            a++;
            b++;
            c++;
        }
        else if (A.data[a].i < B.data[b].i || (A.data[a].i == B.data[b].i && A.data[a].j < B.data[b].j))
        {
            C.data[c] = A.data[a];
            a++;
            c++;
        }
        else if (B.data[b].i < A.data[a].i || (B.data[b].i == A.data[a].i && B.data[b].j < A.data[a].j))
        {
            C.data[c] = B.data[b];
            b++;
            c++;
        }
    }

    // 处理剩余元素
    while (a <= A.tu)
    {
        C.data[c] = A.data[a];
        a++;
        c++;
    }
    while (b <= B.tu)
    {
        C.data[c] = B.data[b];
        b++;
        c++;
    }

    C.tu = c - 1; // 更新非零元素总数
}

// 输出
void PrintMatrix(const TSMatrix &matrix)
{
    cout << "Sparse Matrix (" << matrix.mu << "x" << matrix.nu << "):" << endl;
    cout << left << setw(10) << "Row" << setw(10) << "Column" << setw(10) << "Value" << endl; // 表头对齐

    for (int k = 1; k <= matrix.tu; k++)
    {
        cout << left << setw(10) << matrix.data[k].i
             << setw(10) << matrix.data[k].j
             << setw(10) << matrix.data[k].e << endl;
    }
}

#endif // MatricesFunction