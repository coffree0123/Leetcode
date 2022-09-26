class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0, star = 0;
        for (char c : s) {
            if (c == '*')
                star += 1;
            else if (c == '(')
                open += 1;
            else {
                if (open > 0)
                    open -= 1;
                else if (star > 0)
                    star -= 1;
                else 
                    return false;
            }
        }
        
        reverse(s.begin(), s.end());
        
        open = 0, close = 0, star = 0;
        for (char c : s) {
            if (c == '*')
                star += 1;
            else if (c == ')')
                close += 1;
            else {
                if (close > 0)
                    close -= 1;
                else if (star > 0)
                    star -= 1;
                else
                    return false;
            }
        }
        
        return true;
    }
};
