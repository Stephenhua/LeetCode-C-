/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.16%)
 * Total Accepted:    219.5K
 * Total Submissions: 481.6K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root ==NULL) return res;
        binaryTreePathsCore(root,res,to_string(root->val));
        return res;
    }

    void binaryTreePathsCore(TreeNode *root,vector<string> &str, string strpath)
    {
        if(root->left==NULL &root->right==NULL)
        {
            str.push_back(strpath);
            return ;
            
        }
        if(root->left!=NULL)
        {
            binaryTreePathsCore(root->left,str,strpath+"->"+to_string(root->left->val));
        }
        if(root->right!=NULL)
        {
            binaryTreePathsCore(root->right,str,strpath+"->"+to_string(root->right->val));
        }
    }
};

