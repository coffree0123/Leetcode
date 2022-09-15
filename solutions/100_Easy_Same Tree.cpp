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
    bool same;
public:
    void traversal(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr)
            return;
        
        if (p == nullptr || q == nullptr || p -> val != q -> val) {
            same = false;
            return;
        }
        
        traversal(p -> left, q -> left);
        traversal(p -> right, q -> right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        same = true;
        traversal(p, q);
        
        return same;
    }
};
