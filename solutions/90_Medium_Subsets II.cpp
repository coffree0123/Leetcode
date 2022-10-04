class Solution {
public:
    void dfs(vector<pair<int, int>> nums, int idx, vector<int> tmp, vector<vector<int>> &res) {
        if (idx == nums.size()) {
            // Here make this algorithm O(n * 2^n) not O(2^n) since each tmp end up copy to res cost O(n)
            res.push_back(tmp);
            return;
        }

        int value = nums[idx].first;
        int count = nums[idx].second;

        dfs(nums, idx+1, tmp, res);
        for (int i = 1; i <= count; i++) {
            tmp.push_back(value);
            dfs(nums, idx+1, tmp, res);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (int v : nums)
            umap[v] += 1;

        vector<pair<int, int>> number;      
        for (auto m : umap) {
            number.push_back({m.first, m.second});
        }

        vector<int> tmp;
        vector<vector<int>> res;
        dfs(number, 0, tmp, res);
        return res;
    }
};
