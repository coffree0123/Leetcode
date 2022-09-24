class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int farest = 0;
        
        for (int i = 0, end = farest; i < nums.size() && end < nums.size()-1; i++) {
            farest = max(farest, i + nums[i]);
            if (i == end) {
                end = farest;
                jump += 1;
            }
        }
        
        return jump;
    }
};
