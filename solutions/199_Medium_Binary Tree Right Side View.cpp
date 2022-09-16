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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode *> q;
        
        if (root)
            q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            ans.push_back(q.front() -> val);
            
            for (int i = 0; i < size; i++) {
                if (q.front() -> right)
                    q.push(q.front() -> right);
                
                if (q.front() -> left)
                    q.push(q.front() -> left);
                
                q.pop();
            }
        }
        
        return ans;
    }
};
