class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        int mod = 1000000000 + 7;
        vector<int> st;
        vector<int> dp(arr.size(), 0);
        
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] <= arr[st.back()]) {
                st.pop_back();
            }
            
            if (st.empty()) {
                dp[i] = arr[i] * (i + 1);
            } else {
                dp[i] = dp[st.back()] + arr[i] * (i - st.back());
            }
            
            ans += dp[i];
            st.push_back(i);
        }
        
        
        
        return ans % mod;
    }
};
