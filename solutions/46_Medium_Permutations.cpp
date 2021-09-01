#include <vector>
using namespace std;

class Solution
{
public:
    void find_permutation(vector<vector<int>> &answer, vector<int> cur_answer, vector<int> nums, vector<bool> is_used)
    {
        if (cur_answer.size() == nums.size())
        {
            answer.push_back(cur_answer);
            return;
        }

        for (int idx = 0; idx < nums.size(); idx++)
        {
            if (!is_used.at(idx))
            {
                cur_answer.push_back(nums.at(idx));
                is_used.at(idx) = true;
                find_permutation(answer, cur_answer, nums, is_used);
                cur_answer.pop_back();
                is_used.at(idx) = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> cur_answer;
        vector<vector<int>> answer;
        vector<bool> is_used(nums.size(), 0);

        find_permutation(answer, cur_answer, nums, is_used);

        return answer;
    }
};