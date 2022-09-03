class Solution {
public:
    int counts(vector<int> &piles, int k) {
        int cost = 0;
        for (int p : piles) {
            cost += p / k;
            if (p % k != 0) {
                cost += 1;
            }
        }
        
        return cost;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int bound = 0;
        for (int v : piles)
            bound = max(bound, v);
        
        int left = 1, right = bound;
        
        while (left < right) {
            int mid = (left + right) / 2;
            int cost = counts(piles, mid);
            
            if (cost > h) {
                left = mid + 1;
            } else if (cost < h) {
                right = mid;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
