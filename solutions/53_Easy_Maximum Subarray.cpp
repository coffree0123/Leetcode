#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_value = findMaxSubArray(nums, 0, nums.size());
        return max_value;
    }

    int findMaxSubArray(vector<int> &nums, int left, int right)
    {
        if (right - left <= 1)
            return nums.at(left);
        int middle = left + ((right - left) / 2);
        int left_max = findMaxSubArray(nums, left, middle);
        int right_max = findMaxSubArray(nums, middle, right);
        int middle_max = findMiddleMax(nums, left, right);

        return max(middle_max, max(left_max, right_max));
    }

    int findMiddleMax(vector<int> &nums, int left, int right)
    {
        int cur_sum;
        int middle = left + ((right - left) / 2);

        // Find max value from middle-1 to left.
        cur_sum = 0;
        int left_max = -1000000;
        for (int idx = middle - 1; idx >= left; idx--)
        {
            cur_sum += nums.at(idx);
            left_max = max(left_max, cur_sum);
        }

        // Find max value from middle to right.
        cur_sum = 0;
        int right_max = -1000000;
        for (int idx = middle; idx < right; idx++)
        {
            cur_sum += nums.at(idx);
            right_max = max(right_max, cur_sum);
        }

        return left_max + right_max;
    }
};