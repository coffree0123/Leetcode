class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> umap;
        
        for (int i = 0; i < s.size(); i++) {
            umap[s[i]] = i;
        }
        
        vector<int> ans;
        int farest = 0;
        for (int i = 0, start = 0; i < s.size(); i++) {
            farest = max(farest, umap[s[i]]);
            
            if (i == farest) {
                // Done one group
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};
