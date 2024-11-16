#include <bits/stdc++.h>
#include "TreeFunction.cpp"

using namespace std;

int main()
{
    BiTree T;
    InitBiTree(T);
    cout << "初始化完成" << endl;

    cout << "此时二叉树是否为空?" << (BiTreeEmpty(T) ? "Yes" : "No") << endl;
    cout << "======================================" << endl;

    T = CreateNode(1);
    T->lchild = CreateNode(2);
    T->rchild = CreateNode(3);
    T->lchild->lchild = CreateNode(4);
    T->lchild->rchild = CreateNode(5);

    cout << "创建二叉树完成" << endl;
    cout << "此时二叉树的样子:" << endl;
    cout << "    1" << endl;
    cout << "   / \\" << endl;
    cout << "  2   3" << endl;
    cout << " / \\" << endl;
    cout << "4   5" << endl;

    cout << "此时二叉树是否为空?" << (BiTreeEmpty(T) ? "Yes" : "No") << endl;

    cout << "此时二叉树的深度:" << BiTreeDepth(T) << endl;

    cout << "值为的4节点的父节点:" << Parent(T, 4) << endl;

    cout << "值为的2节点的左子节点:" << LeftChild(T, 2) << endl;

    cout << "值为的2节点的右子节点:" << RightChild(T, 2) << endl;

    cout << "值为的5节点的左兄弟节点:" << LeftSibling(T, 5) << endl;

    cout << "值为的4节点的右兄弟节点:" << RightSibling(T, 4) << endl;

    cout << "======================================" << endl;

    BiTree C;
    InitBiTree(C);
    C = CreateNode(6);
    C->lchild = CreateNode(7);
    C->rchild = CreateNode(8);
    C->lchild->lchild = CreateNode(9);
    C->rchild->rchild = CreateNode(10);

    cout << "构造一棵新的树C" << endl;
    cout << "这棵二叉树的样子:" << endl;
    cout << "    6" << endl;
    cout << "   / \\" << endl;
    cout << "  7   8" << endl;
    cout << " /     \\" << endl;
    cout << "9       10" << endl;
    cout << "======================================" << endl;

    cout << "尝试插入值为2的节点的右子树" << endl;
    bool flag = InsertChild(T, 2, 1, C); // 插入右子树
    if (!flag)
    {
        cout << "值为2的节点存在右子树,失败" << endl;
    }

    cout << "尝试插入值为3的节点的左子树" << endl;
    flag = InsertChild(T, 3, 0, C); // 插入左子树
    if (flag)
    {
        cout << "插入成功" << endl;
    }

    cout << "尝试删除值为8的右子树" << endl;
    flag = DeleteChild(T, 8, 1); // 删除右子树
    if (flag)
    {
        cout << "删除成功" << endl;
    }

    cout << "======================================" << endl;

    cout << "此时二叉树的样子:" << endl;
    cout << "     1" << endl;
    cout << "   /   \\" << endl;
    cout << "  2     3" << endl;
    cout << " / \\   /" << endl;
    cout << "4   5 6" << endl;
    cout << "     / \\" << endl;
    cout << "    7   8" << endl;
    cout << "   /" << endl;
    cout << "  9" << endl;

    cout << "此时值为6的节点的父节点为:" << Parent(T, 6) << endl;

    cout << "值为的6节点的右子节点:" << RightChild(T, 6) << endl;

    cout << "值为的7节点的右兄弟节点:" << RightSibling(T, 7) << endl;

    cout << "前序遍历:";
    PreorderTraverse(T);
    cout << endl;

    cout << "中序遍历:";
    InorderTraverse(T);
    cout << endl;

    cout << "后序遍历:";
    PostorderTraverse(T);
    cout << endl;

    cout << "按层级遍历:";
    LevelTraverse(T);
    cout << endl;

    cout << "======================================" << endl;

    DestroyBiTree(T);
    cout << "摧毁树,程序结束" << endl;

    return 0;
}
