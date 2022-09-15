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
    int maxLen;
public:
    int findMaxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        
        // Find cur diameter
        int left = findMaxDepth(root -> left);
        int right = findMaxDepth(root -> right);
        
        maxLen = max(maxLen, left + right);
        
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxLen = 0;
        findMaxDepth(root);
        
        return maxLen;
    }
};
