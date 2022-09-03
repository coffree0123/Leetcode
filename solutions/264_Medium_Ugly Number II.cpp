class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        unordered_set<int> used;
        
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; i++) {
            int minimum = min({ugly[p2] * 2, ugly[p3] * 3, ugly[p5] * 5});
            ugly[i] = minimum;
            
            if (minimum == ugly[p2] * 2)
                p2 += 1;
            if (minimum == ugly[p3] * 3)
                p3 += 1;
            if (minimum == ugly[p5] * 5)
                p5 += 1;
            
            cout << minimum << " ";
        }
        
        return ugly[n-1];
    }
};
