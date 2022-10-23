class Solution {
public:
    vector<int> mostCompetitive(vector<int>& A, int k) {
        vector<int> st;
        vector<int> leftSmallerIdx(A.size(), -1);
        for (int i = A.size()-1; i >= 0; i--) {
            while (!st.empty() && A[i] <= A[st.back()]) {
                st.pop_back();
            }
            
            if (!st.empty()) {
                leftSmallerIdx[i] = st.back();
            }
            
            st.push_back(i);
        }
        
        vector<int> res;
        for (int i = 0; i < A.size(); i++) {
            if (leftSmallerIdx[i] != -1) {
                int remain = A.size() - leftSmallerIdx[i];
                if (remain < k) {
                    res.push_back(A[i]);
                    k -= 1;
                }
            } else {
                if (k > 0) {
                    res.push_back(A[i]);
                    k -= 1;
                }
            }
        }
        
        return res;
    }
};
