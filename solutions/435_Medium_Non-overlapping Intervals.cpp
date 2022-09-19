class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](auto &v1, auto &v2) {
               return v1[1] < v2[1]; 
        });
        
        int total = 0;
        int endTime = -500000;
        for (auto & v : intervals) {
            if (v[0] >= endTime) {
                total += 1;
                endTime = v[1];
            }
        }
        
        return intervals.size() - total;
    }
};
