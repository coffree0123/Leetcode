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
    unordered_map<int, int> umap;
public:
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_r - pre_l == 1) {
            return new TreeNode(preorder[pre_l]);
        }
        
        if (pre_r - pre_l < 1) {
            return nullptr;
        }
        
        TreeNode *cur = new TreeNode(preorder[pre_l]);
        
        // Find index in inorder
        int index = umap[preorder[pre_l]];
        
        int sizeL = index - in_l;
        
        TreeNode *left = build(preorder, inorder, pre_l+1, pre_l+sizeL+1, in_l, index);
        TreeNode *right = build(preorder, inorder, pre_l+sizeL+1, pre_r, index+1, in_r);
        
        cur -> left = left;
        cur -> right = right;
        
        return cur;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            umap[inorder[i]] = i;

        return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
