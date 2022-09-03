class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int target = 0;
        for (int v : nums)
            target ^= v;
        for (int i = 0; i <= nums.size(); i++)
            target ^= i;
        
        return target;
    }
};
