class Solution {
public:
    bool validPartition(vector<int>& nums) {
        if (nums.size() == 2)
            return (nums[0] == nums[1]);
        // Define dp[i] means [0...i] can be partition or not
        vector<bool> dp(nums.size(), false);
        if (nums[0] == nums[1])
            dp[1] = true;
        if (nums[0] == nums[1] && nums[1] == nums[2])
            dp[2] = true;
        if (nums[1] == nums[0] + 1 && nums[2] == nums[1] + 1)
            dp[2] = true;
        
        for (int i = 3; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] && dp[i-2])
                dp[i] = true;
            if (nums[i] == nums[i-1] && nums[i-1] == nums[i-2] && dp[i-3])
                dp[i] = true;
            if (nums[i] == nums[i-1] + 1 && nums[i-1] == nums[i-2] + 1 && dp[i-3])
                dp[i] = true;
        }
        
        return dp[nums.size()-1];
    }
};
