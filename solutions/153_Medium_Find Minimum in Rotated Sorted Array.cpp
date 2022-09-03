class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums.back())
            return nums[0];

        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Detect mid is on left side or right side
            if (nums[mid] >= nums[0]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return nums[left];
    }
};
