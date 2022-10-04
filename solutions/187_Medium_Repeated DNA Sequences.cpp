class Solution {
public:
    int get_id(char c) {
        if (c == 'A') return 1;
        if (c == 'C') return 2;
        if (c == 'G') return 3;
        if (c == 'T') return 4;
        return -1;
    }

    vector<string> findRepeatedDnaSequences(string s) {
        int p = 5;
        long long mod = 1e9 + 7;
        long long pow = 1;

        for (int i = 1; i <= 10; i++)
            pow = (pow * p) % mod;

        vector<string> res;

        unordered_set<long long> used;
        unordered_map<long long, string> umap;
        long long curHash = 0;
        for (int l=0, r=0; r < s.size(); r++) {
            curHash = (curHash * p) % mod + (get_id(s[r]));
            if (r - l + 1 > 10) {
                curHash = (curHash - (get_id(s[l]) * pow) % mod + mod) % mod;
                l += 1;
            }

            if (r - l + 1 == 10) {
                if (umap.count(curHash) && !used.count(curHash)) {
                    res.push_back(umap[curHash]);
                    used.insert(curHash);
                }
                
                if (!umap.count(curHash))
                    umap[curHash] = s.substr(l, 10);
            }
        }

        return res;
    }
};
