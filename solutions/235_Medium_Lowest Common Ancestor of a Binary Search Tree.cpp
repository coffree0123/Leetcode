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
    TreeNode *LCA;
public:
    bool traversal(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return false;
        
        bool left = traversal(root -> left, p, q);
        bool right = traversal(root -> right, p, q);
        bool contain = root == p || root == q;
        
        if ((left + right + contain == 2) && LCA == nullptr) {
            LCA = root;
        }
        
        return left || right || contain;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA = nullptr;
        traversal(root, p, q);
    
        return LCA;
    }
};
