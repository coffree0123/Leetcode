class Solution {
public:
    bool check(vector<string> &cur) {
        if (cur.size() == 0) return false;
        for (string &s : cur) {
            if (s.size() == 0) return false;
            int l = 0, r = s.size()-1;
            while (l < r) {
                if (s[l] != s[r]) return false;
                l += 1;
                r -= 1;
            }
        }

        return true;
    }

    void dfs(vector<vector<string>> &res, vector<string> &cur, string tmp, int idx, string &s) {
        if (idx == s.size()) {
            if (!tmp.empty())
                return;
    
            if (check(cur)) {
                res.push_back(cur);
            }

            return;
        }

        tmp.push_back(s[idx]);
        dfs(res, cur, tmp, idx+1, s);

        cur.push_back(tmp);
        tmp = "";

        dfs(res, cur, tmp, idx+1, s);
        cur.pop_back();
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        string tmp;
        dfs(res, cur, tmp, 0, s);
        return res;
    }
};
