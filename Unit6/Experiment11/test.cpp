#include "TreeFunction.cpp"
using namespace std;

// 根据前序和中序建树
BiTree BuildTreeByPreoederAndInorder(const string &preorder, const string &inorder, int preStart, int preEnd, int inStart, int inEnd)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    // 创建当前子树的根节点
    BiTree node = new BiTreeNode;
    node->data = preorder[preStart];
    node->lchild = node->rchild = nullptr;

    int inIndex = inorder.find(node->data);

    // 计算左子树的长度
    int length = inIndex - inStart;

    node->lchild = BuildTreeByPreoederAndInorder(preorder, inorder, preStart + 1, preStart + length, inStart, inIndex - 1);
    node->rchild = BuildTreeByPreoederAndInorder(preorder, inorder, preStart + length + 1, preEnd, inIndex + 1, inEnd);

    return node;
}

// 遍历交换二叉树每个节点的左孩子和右孩子
void SwapChildren(BiTree T)
{
    if (T)
    {
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;

        SwapChildren(T->lchild);
        SwapChildren(T->rchild);
    }
}

// 根据前序建树
BiTree BuildTreeByPreoeder(const string &preorder, int &index)
{

    if (index >= preorder.size() || preorder[index] == '#')
    {
        index++;
        return nullptr;
    }

    // 创建新节点
    BiTree node = new BiTreeNode;
    node->data = preorder[index++];
    node->lchild = BuildTreeByPreoeder(preorder, index);
    node->rchild = BuildTreeByPreoeder(preorder, index);

    return node;
}

// 判断是否为平衡二叉树
bool isBalanced(BiTree T)
{
    if (!T)
    {
        return true;
    }

    int left = BiTreeDepth(T->lchild);
    int right = BiTreeDepth(T->rchild);

    bool flag = abs(right - left) <= 1;

    return flag && isBalanced(T->lchild) && isBalanced(T->rchild);
}

// 计算二叉树节点总数
int CountNodes(BiTree root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return 1 + CountNodes(root->lchild) + CountNodes(root->rchild);
    }
}

int main()
{
    string preorder = "ABCDEFGH";
    string inorder = "CBEDFAGH";

    cout << "根据前后序建树后二叉树的样子:" << endl;
    cout << "     A" << endl;
    cout << "   /   \\" << endl;
    cout << "  B     G" << endl;
    cout << " / \\     \\" << endl;
    cout << "c   D     H  " << endl;
    cout << "   / \\" << endl;
    cout << "  E   F" << endl;

    int n = preorder.size();
    BiTree T = BuildTreeByPreoederAndInorder(preorder, inorder, 0, n - 1, 0, n - 1);
    cout << "后序遍历:";
    PostorderTraverse(T);
    cout << endl;
    cout << "======================================" << endl;

    SwapChildren(T);

    cout << "交换左右孩子后二叉树的样子:" << endl;
    cout << "     A" << endl;
    cout << "   /   \\" << endl;
    cout << "  G     B" << endl;
    cout << " /     / \\" << endl;
    cout << "H     D   C" << endl;
    cout << "     / \\" << endl;
    cout << "    F   E" << endl;

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

    if (isBalanced(T))
    {
        cout << "是平衡树" << endl;
    }
    else
    {
        cout << "不是平衡树" << endl;
    }

    cout << "======================================" << endl;

    string preorder2 = "AGHI####BDF##E##C##";
    int index = 0;
    BiTree T2 = BuildTreeByPreoeder(preorder2, index);
    cout << "根据前序建立的二叉树的样子:" << endl;
    cout << "        A" << endl;
    cout << "      /   \\" << endl;
    cout << "     G     B" << endl;
    cout << "    /     / \\" << endl;
    cout << "   H     D   C" << endl;
    cout << "  /     / \\" << endl;
    cout << " I     F   E" << endl;

    cout << "前序遍历:";
    PreorderTraverse(T2);
    cout << endl;
    cout << "中序遍历:";
    InorderTraverse(T2);
    cout << endl;
    cout << "后序遍历:";
    PostorderTraverse(T2);
    cout << endl;
    cout << "按层级遍历:";
    LevelTraverse(T2);
    cout << endl;

    if (isBalanced(T2))
    {
        cout << "是平衡树" << endl;
    }
    else
    {
        cout << "不是平衡树" << endl;
    }

    cout << "有" << CountNodes(T2) << "个节点" << endl;

    return 0;
}