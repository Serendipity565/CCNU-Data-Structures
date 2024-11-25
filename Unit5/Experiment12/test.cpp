#include "MatricesFunction.cpp"

int main()
{
    TSMatrix A;
    InitMatrix(A, 3, 3);

    AssignValue(A, 1, 1, 5);
    AssignValue(A, 1, 2, 3);
    AssignValue(A, 2, 3, 7);

    // 尝试插入异常元素
    AssignValue(A, 5, 5, 2);

    // 尝试插入已有元素的位置
    AssignValue(A, 1, 1, 5);

    PrintMatrix(A);

    TSMatrix B;
    InitMatrix(B, 3, 3);

    AssignValue(B, 3, 2, 5);
    AssignValue(B, 2, 3, 3);
    AssignValue(B, 3, 3, 7);

    PrintMatrix(B);

    TSMatrix C;

    InitMatrix(C, 3, 3);

    AddMatrices(A, B, C);

    PrintMatrix(C);

    return 0;
}
