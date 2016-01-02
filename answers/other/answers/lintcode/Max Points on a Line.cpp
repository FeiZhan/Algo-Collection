/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        if (0 == points.size()) {
            return 0;
        }
        unordered_map<double, int> umap;
        int max_point = 1;
        for (size_t i = 0; i < points.size(); ++ i) {
            umap.clear();
            int same_point = 0;
            int count = 1;
            for (size_t j = i + 1; j < points.size(); ++ j) {
                double slope = numeric_limits<double>::infinity();
                if (points[i].x != points[j].x) {
                    slope = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
                }
                else if (points[i].y == points[j].y) {
                    ++ same_point;
                    continue;
                }
                if (umap.end() == umap.find(slope)) {
                    umap.insert(make_pair(slope, 1));
                }
                ++ umap[slope];
                count = max(count, umap[slope]);
            }
            max_point = max(max_point, count + same_point);
        }
        return max_point;
    }
};
