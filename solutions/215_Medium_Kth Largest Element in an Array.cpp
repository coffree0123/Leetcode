class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0, R = nums.size()-1;
        int p = -1;
        while (p != k-1) {
            p = partition(nums, L, R);
            
            if (p < k-1) {
                L = p + 1;
            } else {
                R = p - 1;
            }
        }
        
        // When p = k-1 means index p is k largest element
        return nums[k-1];
    }
    
    int partition(vector<int> &nums, int L, int R) {
        
        swap(nums[R], nums[L + rand() % (R - L + 1)]);
        int pivot = nums[R];
        
        int idx = L-1;  // Index that last element > pivot
        for (int i = L; i < R; i++) {
            if (nums[i] > pivot) {
                swap(nums[++idx], nums[i]);
            }
        }
        
        swap(nums[++idx], nums[R]);
        
        return idx;
    }
};
