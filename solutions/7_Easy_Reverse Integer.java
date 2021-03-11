class Solution {
    public int reverse(int x) {
        int res;
        int add_number;
        int ans = 0;
        int sign = 1;

        if (x < 0) {
            x = -x;
            sign = -1;
        }

        while (x > 0) {
            ans = 10 * ans;
            add_number = x % 10;
            ans = ans + add_number;
            x = x / 10;
            if (ans == 0) continue;
            // Check if overflow happened.
            if (((Integer.MAX_VALUE / ans) < 10 && x > 0) || (ans < 0))
                return 0;
        }

        return sign * ans;
    }
}