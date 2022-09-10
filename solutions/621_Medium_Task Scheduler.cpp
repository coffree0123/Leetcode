class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        
        for (char c : tasks) {
            count[c - 'A'] += 1;
        }
        
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0)
                pq.push(count[i]);
        }
        
        int time = 0;
        queue<pair<int, int>> q;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            if (p > 1)
                q.push({p-1, time + n + 1});
            
            time += 1;
            
            if (q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
            
            if (pq.empty() && !q.empty()) {
                time = q.front().second;
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};
