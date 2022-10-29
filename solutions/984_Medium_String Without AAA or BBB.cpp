class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        int total = a + b;
        for (int i = 0; i < total; i++) {
            if (a >= b) {
                if (i >= 2 && res[i-1] == 'a' && res[i-2] == 'a') {
                    res.push_back('b');
                    b -= 1;
                } else {
                    res.push_back('a');
                    a -= 1;
                }
            } else {
                if (i >= 2 && res[i-1] == 'b' && res[i-2] == 'b') {
                    res.push_back('a');
                    a -= 1;
                } else {
                    res.push_back('b');
                    b -= 1;
                }
            }
        }
        
        return res;
    }
};
