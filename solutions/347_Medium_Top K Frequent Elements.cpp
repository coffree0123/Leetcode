#include <map>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        map<int, int> mp;
        vector<int> vec;

        for (auto &element : nums)
        {
            mp[element]++;
        }

        for (auto m : mp)
        {
            // Here value in minHeap is pair(times, value)
            minHeap.push({m.second, m.first});
            if (minHeap.size() > k)
                minHeap.pop();
        }

        for (int idx = 0; idx < k; idx++)
        {
            vec.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return vec;
    }
};