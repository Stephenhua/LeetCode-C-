/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    if(NULL == root) return res;
    vector<int> temp;
    int preSum = 0;
    Lv(root, sum, preSum, temp, res);
    return res;
    }
    
    void Lv(TreeNode* root,int sum, int& preSum, vector<int>& temp, vector<vector<int>>& res) {
    if(NULL == root) return;
    //进入节点就push
    preSum += root->val;
    temp.push_back(root->val);
    
    if(!root->left && !root->right)
    {
        if(sum == preSum)
        {
            res.push_back(temp);//路径找到，copy到二维数组中
        }
        preSum -= root->val;
        temp.pop_back();
        return;
    }
    
    Lv(root->left, sum, preSum, temp, res);
    Lv(root->right, sum, preSum, temp, res);
    //离开节点就pop
    preSum -= root->val;
    temp.pop_back();
    }
};
