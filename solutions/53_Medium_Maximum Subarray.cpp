class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int curMax = 0;
        
        for (int v : nums) {
            curMax = max(curMax + v, v);
            maximum = max(maximum, curMax);
        }
        
        return maximum;
    }
};
