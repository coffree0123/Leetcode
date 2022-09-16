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
    int count;
    int ans;
public:
    void inorder(TreeNode *root, int k) {
        if (!root) return;
        
        inorder(root -> left, k);
        
        count += 1;
        
        if (count == k)
            ans = root -> val;
        
        inorder(root -> right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        
        inorder(root, k);
        
        return ans;
    }
};
