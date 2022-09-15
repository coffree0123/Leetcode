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
public:
    bool isSame(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return true;
        
        if (p == nullptr || q == nullptr || p -> val != q -> val)
            return false;
        
        return isSame(p -> left, q -> left) && isSame(p -> right, q -> right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return subRoot == nullptr;
        
        // Check if cur node equal to sub tree
        if (isSame(root, subRoot))
            return true;
        
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};
