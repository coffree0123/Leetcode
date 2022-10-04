class Solution {
public:
    void backtracking(vector<int> &nums, vector<vector<int>> &res, vector<int> &used, vector<int> &tmp, int idx) {
        if (idx == nums.size()) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = 1;
                tmp.push_back(nums[i]);
                backtracking(nums, res, used, tmp, idx+1);
                used[i] = 0;
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int>> res;
        vector<int> used(nums.size(), 0);
        backtracking(nums, res, used, tmp, 0);
        return res;
    }
};
