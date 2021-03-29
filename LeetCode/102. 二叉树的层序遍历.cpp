class Solution
{
public:
    vector <vector<int>> levelOrder(TreeNode* root)
    {
        if(!root)
        {
            return vector < vector < int >> ();
        }

        vector <vector<int>> res;
        queue < TreeNode * > q;

        q.push(root);
        while(!q.empty())
        {
            int num = q.size();
            res.push_back(vector<int>());

            for(int i = 0; i < num; i++)
            {
                TreeNode* temp = q.front();
                res.back().push_back(temp->val);

                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }

                q.pop();
            }
        }

        return res;
    }
};