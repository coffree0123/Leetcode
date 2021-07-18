#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // Divide and conquer.
        int max_profit = getMaxProfit(prices, 0, prices.size());
        return max_profit;
    }

    int getMaxProfit(vector<int> &prices, int left, int right)
    {
        if (right - left == 2)
            return max(0, prices.at(right - 1) - prices.at(left));
        else if (right - left <= 1)
            return 0;

        int middle = left + ((right - left) / 2);

        int left_max = getMaxProfit(prices, left, middle);
        int right_max = getMaxProfit(prices, middle, right);
        int cross_max = getCrossMax(prices, left, right);

        return max(0, max(cross_max, max(left_max, right_max)));
    }

    int getCrossMax(vector<int> &prices, int left, int right)
    {
        // Find left minimum and right maximum and conbime them.
        int middle = left + ((right - left) / 2);
        int minimum = 1000000;
        int maximum = -100000;

        // Find left minimum.
        for (int idx = left; idx < middle; idx++)
        {
            int current_price = prices.at(idx);
            if (current_price <= minimum)
                minimum = current_price;
        }

        // Find right maximum.
        for (int idx = middle; idx < right; idx++)
        {
            int current_price = prices.at(idx);
            if (current_price >= maximum)
                maximum = current_price;
        }

        return maximum - minimum;
    }
};