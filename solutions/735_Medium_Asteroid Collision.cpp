// Input: [5, 10, -5]
// Output: [5, 10]

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        vector<int> ans;
        for (int m : asteroids) {
            if (m < 0) {
                while (!st.empty() && st.back() + m < 0) {
                    st.pop_back();
                }

                if (st.empty()) {
                    ans.push_back(m);
                } else if (st.back() + m == 0) {
                    st.pop_back();
                } else {
                    // Do nothing
                }
                
                
            } else {
                st.push_back(m);
            }
        }
        
        for (int m : st)
            ans.push_back(m);
        
        return ans;
    }
};
