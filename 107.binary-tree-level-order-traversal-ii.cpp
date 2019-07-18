/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (45.81%)
 * Total Accepted:    218.4K
 * Total Submissions: 472.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        if(root==NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        temp.push_back(root->val);
        res.push_back(temp);
        temp.clear();

        while(!q.empty())
        {
            
            int size=q.size();
            while(size>0)
            {
                TreeNode * a=q.front();
                q.pop();
                if(a->left!=NULL)
                {
                    q.push(a->left);
                    temp.push_back(a->left->val);

                }
                if(a->right!=NULL)
                {
                    q.push(a->right);
                    temp.push_back(a->right->val);
                }
                size--;
            }
            if(temp.size()>0)
            {
                res.push_back(temp);
            }
            temp.clear();
            
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};

