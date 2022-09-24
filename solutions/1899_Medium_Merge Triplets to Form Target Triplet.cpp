class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool valid[3] = {};
        for (auto &v : triplets) {
            if (v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]) {
                // Only consider legal triplet
                valid[0] |= (v[0] == target[0]);
                valid[1] |= (v[1] == target[1]);
                valid[2] |= (v[2] == target[2]);
            }
        }
        
        return (valid[0] + valid[1] + valid[2] == 3);
    }
};
