class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        std::vector<int>::const_iterator peak = findPeakElement(num.begin(), num.end());
		if (num.end() == peak) {
			return NULL;
		}
		return peak - num.begin();
    }
    std::vector<int>::const_iterator findPeakElement(const std::vector<int>::const_iterator num_begin, const std::vector<int>::const_iterator num_end) {
		if (num_begin >= num_end) {
			// set num_end as invalid
			return num_end;
		}
		else if (num_end - num_begin == 1) {
			return num_begin;
		}
		else if (num_end - num_begin == 2) {
			return *num_begin > *(num_begin + 1) ? num_begin : num_begin + 1;
		}
		else {
			std::vector<int>::const_iterator num_median = num_begin + (num_end - num_begin) / 2;
			if (*num_median > *(num_median - 1) && *num_median > *(num_median + 1)) {
				return num_median;
			}
			else {
				std::vector<int>::const_iterator peak_left = findPeakElement(num_begin, num_median);
				if (peak_left == num_begin && *peak_left > *(peak_left + 1)) {
					return peak_left;
				}
				else if (*peak_left > *(peak_left - 1) && *peak_left > *(peak_left + 1)) {
					return peak_left;
				}
				std::vector<int>::const_iterator peak_right = findPeakElement(num_median, num_end);
				if (peak_right == num_end - 1 && *peak_right > *(peak_right - 1)) {
					return peak_right;
				}
				else if (*peak_right > *(peak_right - 1) && *peak_right > *(peak_right + 1)) {
					return peak_right;
				}
			}
		}
		return num_end;
	}
};
