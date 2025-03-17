#include <bits/stdc++.h>
using namespace std;

struct AVLNode
{
    int data;
    int height;
    AVLNode *lchild;
    AVLNode *rchild;
};
typedef AVLNode *AVLTree;

AVLTree newNode(int n)
{
    AVLNode *NewNode = new AVLNode;
    NewNode->data = n;
    NewNode->height = 1;
    NewNode->lchild = nullptr;
    NewNode->rchild = nullptr;
    return NewNode;
}

int getHeight(AVLTree TreeNode)
{
    if (TreeNode == nullptr)
    {
        return 0;
    }
    return TreeNode->height;
}

int getBalance(AVLTree TreeNode)
{
    if (TreeNode == nullptr)
    {
        return 0; // 保护性代码，避免空指针解引用
    }
    return getHeight(TreeNode->lchild) - getHeight(TreeNode->rchild);
}

int max(int a, int b)
{
    if (a >= b)
        return a;
    return b;
}

AVLTree leftRotate(AVLTree root)
{ // 1.当前节点的右子树会作为新树的根节点
  // 2.当前节点会作为新树的根节点的左子树
  // 3.如果新的树根 原本有左子树，原本的左子树(LTree) 就作为旧根节点(root)的右子树(->rchild)

    AVLNode *NewRoot = root->rchild;
    // LTree保存新树根原来的左子树
    AVLNode *LTree = NewRoot->lchild;

    // 2.当前节点(root)会作为新树的根节点(NewRoot)的左子树(->lchild)
    NewRoot->lchild = root;
    root->rchild = LTree;

    // 更新树高，root NewRoot
    root->height = 1 + max(getHeight(root->lchild), getHeight(root->rchild));
    NewRoot->height = 1 + max(getHeight(NewRoot->lchild), getHeight(NewRoot->rchild));

    return NewRoot;
}

AVLTree rightRotate(AVLTree root)
{ // 与左旋同理，一切反过来就行
    AVLNode *NewRoot = root->lchild;
    AVLNode *RTree = NewRoot->rchild;

    NewRoot->rchild = root;
    root->lchild = RTree;

    root->height = max(getHeight(root->lchild), getHeight(root->rchild));
    NewRoot->height = max(getHeight(NewRoot->lchild), getHeight(NewRoot->rchild));

    return NewRoot;
}

AVLTree insertNode(AVLTree TreeNode, int n)
{
    // 插入数据
    if (TreeNode == nullptr)
        return newNode(n);

    if (n < TreeNode->data)
        TreeNode->lchild = insertNode(TreeNode->lchild, n);
    else if (n > TreeNode->data)
        TreeNode->rchild = insertNode(TreeNode->rchild, n);
    else
        return TreeNode;

    // 更新树高
    TreeNode->height = 1 + max(getHeight(TreeNode->lchild), getHeight(TreeNode->rchild));

    // 获取当前的节点的平衡因子
    int balance = getBalance(TreeNode); // 此处不取绝对值是为了判断是什么类型的失衡
    // 我们是否需要调整这个树，取决于平衡因子的绝对值是否大于1
    // LL型失衡
    if (balance > 1 && getBalance(TreeNode->lchild) > 0)
    {
        return rightRotate(TreeNode);
    }
    // LR型失衡
    else if (balance > 1 && getBalance(TreeNode->lchild) < 0)
    {
        TreeNode->lchild = leftRotate(TreeNode->lchild);
        return rightRotate(TreeNode);
    }
    // RR型失衡
    else if (balance < -1 && getBalance(TreeNode->rchild) < 0)
    {
        return leftRotate(TreeNode);
    }
    // RL型失衡
    else if (balance < -1 && getBalance(TreeNode->rchild) > 0)
    {
        TreeNode->rchild = rightRotate(TreeNode->rchild);
        return leftRotate(TreeNode);
    }

    return TreeNode;
}

void preTree(AVLTree Tree)
{
    if (Tree == nullptr)
        return;
    cout << Tree->data << " ";
    preTree(Tree->lchild);
    preTree(Tree->rchild);
}

void midTree(AVLTree Tree)
{
    if (Tree == nullptr)
        return;
    midTree(Tree->lchild);
    cout << Tree->data << " ";
    midTree(Tree->rchild);
}

AVLTree search(AVLTree root, int t, int &counter)
{
    AVLNode *curr = root;
    while (curr != nullptr)
    {
        counter++;
        if (t < curr->data)
        {
            curr = curr->lchild;
        }
        else if (t > curr->data)
        {
            curr = curr->rchild;
        }
        else
        {
            return curr;
        }
    }
    return nullptr;
}

AVLTree deleteNode(AVLTree TreeNode, int t)
{
    if (TreeNode == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (t < TreeNode->data)
        {
            TreeNode->lchild = deleteNode(TreeNode->lchild, t);
            return TreeNode;
        }
        else if (t > TreeNode->data)
        {
            TreeNode->rchild = deleteNode(TreeNode->rchild, t);
            return TreeNode;
        }
        else
        {
            if (TreeNode->lchild == nullptr && TreeNode->rchild == nullptr)
            {
                delete TreeNode;
                return nullptr;
            }
            else if (TreeNode->lchild != nullptr && TreeNode->rchild == nullptr)
            {
                AVLNode *temp = TreeNode->lchild;
                delete TreeNode;
                return temp;
            }
            else if (TreeNode->lchild == nullptr && TreeNode->rchild != nullptr)
            {
                AVLNode *temp = TreeNode->rchild;
                delete TreeNode;
                return temp;
            }
            else
            {
                AVLNode *curr = TreeNode->lchild;
                while (curr->rchild != nullptr)
                {
                    curr = curr->rchild;
                }
                TreeNode->data = curr->data;
                TreeNode->lchild = deleteNode(TreeNode->lchild, curr->data);
            }
        }
    }
    // 删除完毕 接下来对平衡性进行调整
    if (TreeNode == nullptr)
    {
        return TreeNode;
    }
    // 更新树高
    TreeNode->height = 1 + max(getHeight(TreeNode->lchild), getHeight(TreeNode->rchild));

    // 获取当前的节点的平衡因子
    int balance = getBalance(TreeNode); // 此处不取绝对值是为了判断是什么类型的失衡
    // 我们是否需要调整这个树，取决于平衡因子的绝对值是否大于1
    // LL型失衡
    if (balance > 1 && getBalance(TreeNode->lchild) >= 0)//此处为何与前面的不同，详细请见视频或等我以后出Markdown
    {
        return rightRotate(TreeNode);
    }
    // LR型失衡
    else if (balance > 1 && getBalance(TreeNode->lchild) < 0)
    {
        TreeNode->lchild = leftRotate(TreeNode->lchild);
        return rightRotate(TreeNode);
    }
    // RR型失衡
    else if (balance < -1 && getBalance(TreeNode->rchild) <= 0)
    {
        return leftRotate(TreeNode);
    }
    // RL型失衡
    else if (balance < -1 && getBalance(TreeNode->rchild) > 0)
    {
        TreeNode->rchild = rightRotate(TreeNode->rchild);
        return leftRotate(TreeNode);
    }

    return TreeNode;
}

int main()
{
    AVLTree root = nullptr;

    // 插入节点
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 70);
    root = insertNode(root, 80);

    // 搜索节点
    int counter = 0;
    search(root, 70, counter);
    cout << "70" << " 于第 " << counter << " 次找到" << endl;

    cout << "先序遍历结果（插入后）：" << endl;
    preTree(root);
    cout << endl;

    cout << "中序遍历结果（插入后）：" << endl;
    midTree(root);
    cout << endl;

    // 删除节点，测试删除操作
    cout << "删除节点 20" << endl;
    root = deleteNode(root, 20);

    cout << "删除节点 50" << endl;
    root = deleteNode(root, 50);

    // 再次遍历树，验证删除操作
    cout << "先序遍历结果（删除节点后）：" << endl;
    preTree(root);
    cout << endl;

    cout << "中序遍历结果（删除节点后）：" << endl;
    midTree(root);
    cout << endl;

    return 0;
}