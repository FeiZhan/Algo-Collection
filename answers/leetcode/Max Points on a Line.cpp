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
    int maxPoints(vector<Point> &points) {
		int max_point_num = 0;
		// special case
		if (points.size() == 0) {
			return max_point_num;
		}
		for (size_t i = 0; i < points.size(); ++ i) {
			std::map<double, int> slope_map;
			int same_count = 0;
			int vertical_count = 0;
			for (size_t j = i + 1; j < points.size(); ++ j) {
				if (points[j].x == points[i].x) {
					if (points[j].y == points[i].y) {
						++ same_count;
					} else {
						++ vertical_count;
					}
				} else {
					// don't use abs
					double slope = static_cast<double>(points[j].y - points[i].y) / (points[j].x - points[i].x);
					++ slope_map[slope];
				}
			}
			for (std::map<double, int>::iterator it = slope_map.begin(); it != slope_map.end(); ++ it) {
				if (it->second + same_count > max_point_num) {
					max_point_num = it->second + same_count;
				}
			}
			if (vertical_count + same_count > max_point_num) {
				max_point_num = vertical_count + same_count;
			}
			// if slope_map.size = 0
			if (same_count > max_point_num) {
				max_point_num = same_count;
			}
		}
		// include itself
		return max_point_num + 1;
    }
};
