/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

 // Definition for a binary tree node.
 /* struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };*/
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root ==nullptr)      
            return root;
            
        TreeNode* tempNode=root->left;
        root->left=root->right;
        root->right=tempNode;
        invertTree(root->left);
        invertTree(root->right);


        
        return root;
        
    }
};

