class Solution {
public:
	int findMin(vector<int> &num) {
		int minimum = INT_MAX;
		for (size_t i = 0; i < num.size(); ++ i) {
			if (num[i] < minimum) {
				minimum = num[i];
			}
		}
		return minimum;
	}
};

// http://blog.csdn.net/linhuanmars/article/details/40449299

class Solution {
public:
	int findMin(vector<int> &num) {
		if (0 == num.size()) {
			return 0;
		}
		int left = 0, right = num.size() - 1;
		int min = INT_MAX;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (num[left] < num[mid]) {
				min = std::min(num[left], min);
				left = mid + 1;
			}
			else if (num[left] > num[mid]) {
				min = std::min(num[mid], min);
				right = mid - 1;
			}
			else {
				++ left;
			}
		}
		return std::min(min, std::min(num[left], num[right]));
	}
};

// 2015-01-14
//@type binary search
class Solution {
public:
	int findMin(vector<int> &num) {
		if (0 == num.size()) {
			return 0;
		}
		int left = 0, right = num.size() - 1;
		int min = INT_MAX;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (num[left] < num[mid]) {
				min = std::min(num[left], min);
				left = mid + 1;
			}
			else if (num[left] > num[mid]) {
				min = std::min(num[mid], min);
				right = mid - 1;
			}
			else {
				min = std::min(num[mid], min);
				++ left;
			}
		}
		return min;
	}
};