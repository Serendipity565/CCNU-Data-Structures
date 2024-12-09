#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int weight;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int w) : weight(w), left(nullptr), right(nullptr) {}
};

int WPL(TreeNode *root, int depth)
{
    if (root == nullptr)
    {
        return 0;
    }

    // 如果是叶结点
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->weight * depth;
    }

    // 否则递归计算左右子树的WPL
    return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
}

int main()
{
    // 创建一个简单的二叉树
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    /*
            5
           / \
          3   8
         / \   \
        2   4   7
    */

    // 计算WPL
    int ans = WPL(root, 0); // 从根结点开始，深度为0
    cout << "WPL: " << ans << endl;

    return 0;
}
