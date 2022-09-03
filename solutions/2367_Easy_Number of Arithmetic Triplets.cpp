class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int total = 0;
        int i = 0, j = 0, k = 0;
        for (j = 0; j < nums.size(); j++) {
            int left = 0, right = 0;
            for (; i < j && nums[j] - nums[i] >= diff; i++) {
                if (nums[j] - nums[i] == diff)
                    left += 1;
            }
            
            for (k = j+1; k < nums.size() && nums[k] - nums[j] <= diff; k++) {
                if (nums[k] - nums[j] == diff)
                    right += 1;
            }
            
            total += (left * right);
        }
        
        return total;
    }
};
