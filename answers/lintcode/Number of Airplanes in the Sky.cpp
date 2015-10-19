//@level Medium 
//@type LintCode Copyright Array Interval
//@result Accepted Total Runtime: 1504 ms 100% test cases passed.

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
		map<int, int> time_map;
		for (size_t i = 0; i < airplanes.size(); ++ i) {
			if (time_map.end() == time_map.find(airplanes[i].start)) {
				time_map[airplanes[i].start] = 0;
			}
			++ time_map[airplanes[i].start];
			if (time_map.end() == time_map.find(airplanes[i].end)) {
				time_map[airplanes[i].end] = 0;
			}
			-- time_map[airplanes[i].end];
		}
		int count(0);
		int max_count(0);
		for (map<int, int>::iterator it = time_map.begin(); it != time_map.end(); ++ it) {
			count += it->second;
			max_count = max(max_count, count);
		}
		return max_count;
    }
};
