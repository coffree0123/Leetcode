class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int s) {
        vector<pair<int, int>> adj[n+1];
        vector<bool> visited(n+1, false);
        
        for (auto &v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        vector<int> disFromSource(n+1, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int longest = 0;
        int validCount = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            if (visited[p.second]) continue;
            
            visited[p.second] = true;
            disFromSource[p.second] = p.first;
            longest = max(longest, p.first);
            validCount += 1;
            
            // Relax related vertice
            for (int i = 0; i < adj[p.second].size(); i++) {
                auto nei = adj[p.second][i];
                if (visited[nei.first]) continue;
                if (disFromSource[nei.first] > disFromSource[p.second] + nei.second) {
                    pq.push({disFromSource[p.second] + nei.second, nei.first});
                }
            }
        }
        
        return (validCount == n)? longest : -1;
    }
};
