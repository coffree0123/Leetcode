/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool balance;
public:
    int findMaxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        
        int left = findMaxDepth(root -> left);
        int right = findMaxDepth(root -> right);
        
        if (abs(left - right) > 1)
            balance = false;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        balance = true;
        findMaxDepth(root);
        
        return balance;
    }
};
