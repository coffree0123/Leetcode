class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int L = 0, R = points.size() - 1;
        int p = -1;
        while (p + 1 != k) {
            p = partition(points, L, R);
            
            if (p < k) {
                L = p + 1;
            } else {
                R = p - 1;
            }
        }
        
        // When p = k
        points.resize(k);
        
        return points;
    }
    
    int partition(vector<vector<int>> &points, int L, int R) {
        auto distance = [](auto &p) { return p[0] * p[0] + p[1] * p[1]; };
        
        // Randomized quick select
        srand(time(0));
        swap(points[R], points[L + rand() % (R - L + 1)]);
        
        int pivot = distance(points[R]);
        
        int idx = L-1;   // Last idx that has value smaller than pivot
        
        for (int i = L; i < R; i++) {
            if (distance(points[i]) < pivot) {
                swap(points[++idx], points[i]);
            }
        }
        
        swap(points[++idx], points[R]);

        return idx;
    }
};
