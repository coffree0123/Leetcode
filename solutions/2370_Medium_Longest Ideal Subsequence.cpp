class Solution {
public:
    int longestIdealString(string s, int k) {
        // Define dp[i] means [0...i] longest subsequence that end at i which satisfy the condition
        // We also maintain a map that the last char a..z appear in string s
        vector<int> dp(s.size());
        vector<int> lastAppear(26, -1);
        
        dp[0] = 1;
        lastAppear[s[0]-'a'] = 0;
        int maximum = 1;
        for (int i = 1; i < s.size(); i++) {
            int cur = s[i] - 'a';
            int longest = 1;
            for (int c = 0; c < 26; c++) {
                if (abs(cur - c) <= k && lastAppear[c] != -1) {
                    longest = max(longest, dp[lastAppear[c]] + 1);
                }
            }
            lastAppear[cur] = i;
            dp[i] = longest;
            maximum = max(maximum, dp[i]);
        }
        
        return maximum;
    }
};
