#include <bits/stdc++.h>
#include "TreeFunction.cpp"
using namespace std;

// 提供了两种方法，一种是类似于终端查看文件夹的树状结构
// 另一种是将二叉树转换为数组，再打印数组以实现树的直观输出

// 创建二叉树
BiTree buildTree()
{
    BiTreeNode *nodes[10];
    for (int i = 0; i < 10; ++i)
    {
        nodes[i] = new BiTreeNode;
        nodes[i]->data = 'A' + i;
        nodes[i]->lchild = nodes[i]->rchild = nullptr;
    }

    nodes[0]->lchild = nodes[1];
    nodes[0]->rchild = nodes[2];
    nodes[1]->lchild = nodes[3];
    nodes[1]->rchild = nodes[4];
    nodes[2]->lchild = nodes[5];
    nodes[3]->rchild = nodes[6];
    nodes[4]->lchild = nodes[7];
    nodes[5]->rchild = nodes[8];
    nodes[6]->rchild = nodes[9];

    return nodes[0];
}

// 树状文件夹风格
void printTree(BiTree root, string prefix = "", bool isLeft = true)
{
    if (root == nullptr)
    {
        return;
    }

    // 打印附加前缀
    cout << prefix;
    // 判断是左子树还是右子树
    cout << (isLeft ? "|-- " : "\\-- ");
    cout << root->data << endl;

    // 递归
    string newPrefix = prefix + (isLeft ? "|   " : "    ");
    printTree(root->lchild, newPrefix, true);
    printTree(root->rchild, newPrefix, false);
}

void fillArrayTree(BiTree root, vector<vector<char>> &array, int depth, int left, int right)
{
    if (root == nullptr)
    {
        return;
    }

    // 计算当前节点的位置
    int mid = left + (right - left) / 2;
    array[depth][mid] = root->data;

    // 递归填充左右子树
    if (root->lchild)
    {
        array[depth + 1][mid - (right - left + 1) / 4] = '/';
        fillArrayTree(root->lchild, array, depth + 2, left, mid - 1);
    }
    if (root->rchild)
    {
        array[depth + 1][mid + (right - left + 1) / 4] = '\\';
        fillArrayTree(root->rchild, array, depth + 2, mid + 1, right);
    }
}

// 打印二叉树数组
void printArrayTree(BiTree root)
{
    if (root == nullptr)
    {
        return;
    }

    // 计算树的深度
    int depth = BiTreeDepth(root);

    // 计算数组的大小
    int width = pow(2, depth) - 1;

    // 初始化数组
    vector<vector<char>> array(2 * depth - 1, vector<char>(width, ' '));

    // 递归填充数组
    fillArrayTree(root, array, 0, 0, width - 1);

    // 打印数组
    for (const auto &row : array)
    {
        for (char c : row)
        {
            cout << c;
        }
        cout << endl;
    }
}

int main()
{
    BiTree root = buildTree();

    cout << "二叉树的直观表示（树状文件夹形式）:" << endl;
    cout << "|-- 表示左子树，\\-- 表示右子树" << endl;
    printTree(root);
    cout << endl;

    cout << "二叉树的直观表示:" << endl;
    printArrayTree(root);

    return 0;
}
