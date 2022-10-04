class Solution {
public:
    void backtracking(vector<int> &candidates, vector<vector<int>> &res, vector<int> &tmp, int target, int curSum, int idx) {
        if (curSum > target || idx >= candidates.size()) return;
        if (curSum == target) {
            res.push_back(tmp);
            return;
        }
        
        backtracking(candidates, res, tmp, target, curSum, idx+1);
        tmp.push_back(candidates[idx]);
        backtracking(candidates, res, tmp, target, curSum + candidates[idx], idx);
        tmp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> res;
        backtracking(candidates, res, tmp, target, 0, 0);
        return res;
    }
};
