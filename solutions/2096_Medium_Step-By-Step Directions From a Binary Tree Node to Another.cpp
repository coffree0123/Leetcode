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
    bool dfs(TreeNode *root, vector<TreeNode *> &backLink, int value) {
        if (root == nullptr) return false;
        if (root -> val == value) {
            backLink.push_back(root);
            return true;
        }
        
        backLink.push_back(root);
        if (dfs(root -> left, backLink, value)) {
            return true;
        }
        
        if (dfs(root -> right, backLink, value)) {
            return true;
        }
        
        backLink.pop_back();

        return false;
    }
    
    bool dfss(TreeNode *root, int value, string &ans, unordered_map<int, int> &visited) {
        if (root == nullptr) return false;
        if (root -> val == value) return true;
        if (visited.count(root -> val)) return false;
        
        ans.push_back('L');
        if (dfss(root -> left, value, ans, visited))
            return true;
        ans.pop_back();
        ans.push_back('R');
        if (dfss(root -> right, value, ans, visited))
            return true;
        
        ans.pop_back();
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<TreeNode *> backLink;
        // Find reverse link from start to root
        dfs(root, backLink, startValue);
        reverse(backLink.begin(), backLink.end());
        
        string ans = "";
        unordered_map<int, int> visited;
        for (int i = 0; i < backLink.size(); i++) {
            if (dfss(backLink[i], destValue, ans, visited))
                return ans;
            visited[backLink[i] -> val] = 1;
            ans.push_back('U');
        }
        
        return "";
    }
};
