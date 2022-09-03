class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> counts;
        for (int v : nums)
            counts.insert(v);
        
        int maxGroup = 0;
        for (auto &m : counts) {
            if (!counts.count(m-1)) {
                int v = m;
                int curGroup = 1;
                
                while (counts.count(++v))
                    curGroup += 1;
                
                maxGroup = max(maxGroup, curGroup);
            }
        }
        
        return maxGroup;
    }
};
