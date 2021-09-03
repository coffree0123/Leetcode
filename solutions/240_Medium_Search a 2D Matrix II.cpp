#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;

        bool is_find = false;
        while (row < m and col >= 0)
        {
            int cur_value = matrix[row][col];
            if (cur_value == target)
            {
                is_find = true;
                break;
            }

            if (cur_value > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
        return is_find;
    }
};