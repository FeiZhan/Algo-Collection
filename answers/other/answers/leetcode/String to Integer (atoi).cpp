class Solution {
public:
	int atoi(const char *str) {
		unsigned num = 0;
		int ptr = 0;
		bool start_flag = false;
		bool negative_flag = false;
		while (str[ptr]) {
			if (str[ptr] >= '0' && str[ptr] <= '9') {
				start_flag = true;
				// > , not >=
				if (num > (static_cast<unsigned>(INT_MAX) + 1 - static_cast<unsigned> (str[ptr] - '0')) / 10) {
					num = static_cast<unsigned>(INT_MAX) + 1;
				}
				else {
					num = num * 10 + static_cast<unsigned> (str[ptr] - '0');
				}
			}
			else if (! start_flag && ('-' == str[ptr] || '+' == str[ptr])) {
				start_flag = true;
				negative_flag = '-' == str[ptr];
			}
			else if ('\0' == str[ptr] || ' ' == str[ptr] || '\t' == str[ptr]) {
				if (start_flag) {
					break;
				}
			}
			else {
				break;
			}
			++ ptr;
		}
		if (negative_flag) {
			if (num > 0 && num - 1 >= INT_MAX) {
				return INT_MIN;
			} else {
				return - static_cast<int> (num);
			}
		} else {
			if (num >= INT_MAX) {
				return INT_MAX;
			} else {
				return static_cast<int> (num);
			}
		}
	}
};
