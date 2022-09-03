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
    bool exist;
    unordered_set<int> umap;
    void dfs(TreeNode *root, int k) {
        if (root == nullptr) return;
        if (umap.count(k - root -> val)) {
            exist = true;
        }
        
        umap.insert(root -> val);
        dfs(root -> left, k);
        dfs(root -> right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        exist = false;
        dfs(root, k);
        return exist;
    }
};
