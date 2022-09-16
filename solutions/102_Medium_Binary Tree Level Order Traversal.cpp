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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        queue<TreeNode *> q;
        
        if (root)
            q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> cur;
            
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                cur.push_back(tmp -> val);
                q.pop();
                
                if (tmp -> left)
                    q.push(tmp -> left);
                if (tmp -> right)
                    q.push(tmp -> right);
            }
            
            ans.push_back(cur);
        }
        
        return ans;       
    }
};
