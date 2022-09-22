class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        
        int start = -1, end = -1;
        for (int &time : timeSeries) {
            if (start == -1) {
                start = time;
                end = time + duration;
            } else {
                if (time > end) {
                    total += (end - start);
                    start = time;
                    end = time + duration;
                } else {
                    end = max(end, time + duration);
                }   
            }
        }
        
        total += (end - start);
        
        return total;
    }
};
