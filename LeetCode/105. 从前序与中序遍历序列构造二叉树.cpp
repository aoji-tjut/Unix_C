class Solution
{
public:
    unordered_map<int, int> index;  //中序遍历 节点值->下标

    //先序遍历 中序遍历 先序左边界 先序右边界 中序左边界 中序右边界
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                          int preorder_left, int preorder_right,
                          int inorder_left, int inorder_right)
    {
        if(preorder_left > preorder_right)
        {
            return nullptr;
        }

        // 先序遍历中根节点下标
        int preorder_root = preorder_left;

        // 中序遍历中根节点下标
        int inorder_root = index[preorder[preorder_root]];

        // 根节点值
        int root_val = preorder[preorder_root];

        // 建立根节点
        TreeNode* root = new TreeNode(root_val);

        // 得到左子树中的节点数目
        int left_subtree_size = inorder_root - inorder_left;

        // 递归地构造左子树
        root->left = myBuildTree(preorder, inorder,
                                 preorder_left + 1, preorder_left + left_subtree_size,
                                 inorder_left, inorder_root - 1);

        // 递归地构造右子树
        root->right = myBuildTree(preorder, inorder,
                                  preorder_left + left_subtree_size + 1, preorder_right,
                                  inorder_root + 1, inorder_right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();

        //中序遍历 节点值->下标
        for(int i = 0; i < n; ++i)
        {
            index[inorder[i]] = i;
        }

        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};