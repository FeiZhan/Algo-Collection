class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
		map<char, int> target_map;
		for (size_t i = 0; i < target.length(); ++ i) {
			if (target_map.end() == target_map.find(target[i])) {
				target_map[target[i]] = 0;
			}
			++ target_map[target[i]];
		}
		size_t left(0);
		size_t right(0);
		map<char, int> source_map;
		int count(0);
		size_t min_left(0);
		size_t min_right(source.size());
		while (left <= right && right < source.size()) {
			if (target_map.end() != target_map.find(source[right])) {
				if (source_map.end() == source_map.find(source[right])) {
					source_map[source[right]] = 0;
				}
				++ source_map[source[right]];
				if (source_map[source[right]] <= target_map[source[right]]) {
					++ count;
				}
				//cout << "test1 " << source[left] << " " << source_map[source[left]] << " " << count << endl;
				// reduce immediately
				while (count >= target.length() && (source_map.end() == source_map.find(source[left]) || source_map[source[left]] > target_map[source[left]])) {
					if (source_map.end() != source_map.find(source[left])) {
						-- source_map[source[left]];
					}
					++ left;
				}
				//cout << "test " << source.substr(left, right - left + 1) << " " << count << endl;
				if (count >= target.length() && right - left < min_right - min_left) {
					min_left = left;
					min_right = right;
				}
			}
			++ right;
		}
		// check if no answer
		return source.size() != min_right ? source.substr(min_left, min_right - min_left + 1) : string();
    }
};

