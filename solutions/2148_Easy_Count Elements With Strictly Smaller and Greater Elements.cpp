class Solution {
public:
    int countElements(vector<int>& nums) {
        int maximum = -10000000, minimum = 10000000;
        
        for (int v : nums) {
            maximum = max(maximum, v);
            minimum = min(minimum, v);
        }
        
        int total = 0;
        for (int v : nums) {
            if (v < maximum && v > minimum)
                total += 1;
        }
        
        return total;
    }
};
