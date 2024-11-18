#include <bits/stdc++.h>

#ifndef TreeFunction
#define TreeFunction

using namespace std;

typedef char TElemType;

struct BiTreeNode
{
    TElemType data;
    struct BiTreeNode *lchild, *rchild;
};

typedef BiTreeNode *BiTree;

// 初始化
void InitBiTree(BiTree &T)
{
    T = nullptr;
}

// 销毁树
void DestroyBiTree(BiTree &T)
{
    if (T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        delete T;
        T = nullptr;
    }
}

// 二叉树是否为空
bool BiTreeEmpty(BiTree T)
{
    return T == nullptr;
}

// 二叉树的深度
int BiTreeDepth(BiTree T)
{
    if (T == nullptr)
    {
        return 0;
    }
    else
    {
        return max(BiTreeDepth(T->lchild), BiTreeDepth(T->rchild)) + 1;
    }
}

// 返回父节点
TElemType Parent(BiTree T, TElemType e)
{
    if (T == nullptr)
    {
        return -1;
    }
    if ((T->lchild && T->lchild->data == e) || (T->rchild && T->rchild->data == e))
    {
        return T->data;
    }

    TElemType p = Parent(T->lchild, e);
    if (p != -1)
    {
        return p;
    }

    return Parent(T->rchild, e); // 如果在左子树没找到，去右子树找
}

// 返回左子节点
TElemType LeftChild(BiTree T, TElemType e)
{
    if (T == nullptr)
    {
        return -1;
    }
    if (T->data == e)
    {
        return (T->lchild) ? T->lchild->data : -1;
    }

    TElemType res = LeftChild(T->lchild, e);
    if (res != -1)
    {
        return res;
    }

    return LeftChild(T->rchild, e);
}

// 返回右子节点
TElemType RightChild(BiTree T, TElemType e)
{
    if (T == nullptr)
    {
        return -1;
    }
    if (T->data == e)
    {
        return (T->rchild) ? T->rchild->data : -1;
    }

    TElemType res = RightChild(T->lchild, e);
    if (res != -1)
    {
        return res;
    }

    return RightChild(T->rchild, e);
}

// 返回左兄弟节点
TElemType LeftSibling(BiTree T, TElemType e)
{
    if (T == nullptr || T->data == e)
    {
        return -1;
    }

    TElemType res = Parent(T, e);
    if (res == -1)
    {
        return -1;
    }

    TElemType ans = LeftChild(T, res);
    if (ans == -1)
    {
        return -1;
    }

    return ans;
}

// 返回右兄弟节点
TElemType RightSibling(BiTree T, TElemType e)
{
    if (T == nullptr || T->data == e)
    {
        return -1;
    }

    TElemType res = Parent(T, e);
    if (res == -1)
    {
        return -1;
    }

    TElemType ans = RightChild(T, res);
    if (ans == -1)
    {
        return -1;
    }

    return ans;
}

// 插入子树
// LR为0插左子树，为1插右子树
bool InsertChild(BiTree &T, TElemType p, int LR, BiTree C)
{
    if (T == nullptr)
    {
        return false;
    }

    if (T->data == p)
    {
        if (LR == 0)
        {
            if (T->lchild)
            {
                return false;
            }
            T->lchild = C;
        }
        else
        {
            if (T->rchild)
            {
                return false;
            }
            T->rchild = C;
        }
        return true;
    }

    bool res = InsertChild(T->lchild, p, LR, C);
    if (res)
    {
        return true;
    }

    return InsertChild(T->rchild, p, LR, C);
}

// 删除子树
bool DeleteChild(BiTree &T, TElemType p, int LR)
{
    if (T == nullptr)
    {
        return false;
    }

    if (T->data == p)
    {
        if (LR == 0)
        {
            if (T->lchild)
            {
                DestroyBiTree(T->lchild);
                T->lchild = nullptr;
            }
            return true;
        }
        else
        {
            if (T->rchild)
            {
                DestroyBiTree(T->rchild);
                T->rchild = nullptr;
            }
            return true;
        }
    }

    bool res = DeleteChild(T->lchild, p, LR);
    if (res)
    {
        return true;
    }

    return DeleteChild(T->rchild, p, LR);
}

// 前序遍历
void PreorderTraverse(BiTree T)
{
    if (T)
    {
        cout << T->data << " ";      // 先访问根节点
        PreorderTraverse(T->lchild); // 再递归遍历左子树
        PreorderTraverse(T->rchild); // 最后递归遍历右子树
    }
}

// 中序遍历
void InorderTraverse(BiTree T)
{
    if (T)
    {
        InorderTraverse(T->lchild); // 先递归遍历左子树
        cout << T->data << " ";     // 访问根节点
        InorderTraverse(T->rchild); // 再递归遍历右子树
    }
}

// 后序遍历
void PostorderTraverse(BiTree T)
{
    if (T)
    {
        PostorderTraverse(T->lchild); // 先递归遍历左子树
        PostorderTraverse(T->rchild); // 再递归遍历右子树
        cout << T->data << " ";       // 最后访问根节点
    }
}

// 层级遍历
void LevelTraverse(BiTree T)
{
    if (T == nullptr)
    {
        return;
    }
    queue<BiTree> q;
    q.push(T);

    while (!q.empty())
    {
        BiTree node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->lchild)
        {
            q.push(node->lchild);
        }
        if (node->rchild)
        {
            q.push(node->rchild);
        }
    }
}

// 插入节点
BiTreeNode *CreateNode(TElemType value)
{
    BiTreeNode *newNode = new BiTreeNode();
    newNode->data = value;
    newNode->lchild = newNode->rchild = nullptr;
    return newNode;
}

#endif // TreeFunction
