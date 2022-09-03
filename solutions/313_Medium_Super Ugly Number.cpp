class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<long long> used;
        unordered_map<long long, int> prime2idx;
        vector<int> ans(n, 0);
        ans[0] = 1;
        used.insert(1);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i = 0; i < primes.size(); i++) {
            prime2idx[primes[i]] = 0;
            pq.push({1 * primes[i], primes[i]});
        }
        
        for (int i = 1; i < n;) {
            pair<int, int> p = pq.top();
            pq.pop();
            
            
            long long value = p.first;
            long long prime = p.second;
            int idx = prime2idx[prime] + 1;
            
            if (!used.count(value)) {
                ans[i] = value;
                used.insert(value);
                i += 1;
            }
            
            pq.push({ans[idx] * prime, prime});
            prime2idx[prime] += 1;
        }
        
        return ans[n-1];
    }
};
