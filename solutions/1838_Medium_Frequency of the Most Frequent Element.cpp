class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long cur = 0;
        int maximum = 0;
        for (int l=0, r=0; r < nums.size(); r++) {
            // Calculate freq that have value same as nums[r]
            cur += nums[r];
            while ((r - l + 1) * (long long)nums[r] - cur > k)
                cur -= nums[l++];
            maximum = max(maximum, r - l + 1);
        }
        
        return maximum;
    }
};
