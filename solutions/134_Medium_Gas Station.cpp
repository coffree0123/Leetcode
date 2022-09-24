class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += (gas[i] - cost[i]);
            if (tank < 0) {
                tank = 0;
                start = (i + 1) % gas.size();
            }
        }
        
        // Check if start is correct
        tank = 0;
        for (int i = 0; i < gas.size(); i++) {
            int idx = (start + i) % gas.size();
            tank += (gas[idx] - cost[idx]);
            if (tank < 0)
                return -1;
        }
        
        return start;
    }
};
