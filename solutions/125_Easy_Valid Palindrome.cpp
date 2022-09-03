class Solution {
public:
    bool check(char c) {
        return isalpha(c) || isdigit(c);
    }
    
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left += 1;
            } else if (!isalnum(s[right])) {
                right -= 1;
            } else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            } else {
                left += 1;
                right -= 1;
            }
        }
        
        return true;
    }
};
