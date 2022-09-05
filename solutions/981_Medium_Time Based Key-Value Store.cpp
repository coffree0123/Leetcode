class TimeMap {
    unordered_map<string, vector<pair<int, string>>> umap;
public:
    TimeMap() {
        // Pass
    }
    
    void set(string key, string value, int timestamp) {
        // Since strictly increasing, so only need to push back
        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!umap.count(key))
            return "";

        // Binary search for the first time > timestamp
        vector<pair<int, string>> &v = umap[key];
        
        int left = 0, right = v.size();
        while (left < right) {
            int mid = (left + right) / 2;
            
            pair<int, string> p = v[mid];
            if (p.first < timestamp) {
                left = mid + 1;
            } else if (p.first > timestamp) {
                right = mid;
            } else {
                left = mid + 1;
                right = mid + 1;
            }
        }

        return (left > 0)? v[left-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
