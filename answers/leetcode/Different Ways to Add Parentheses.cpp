//@type Divide and Conquer
//@result 24 / 24 test cases passed. Status: Accepted Runtime: 4 ms You are here! Your runtime beats 46.92% of cpp submissions.

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        num_list.clear();
        op_list.clear();
		for (size_t i = 0; i < input.size(); ++ i) {
			switch (input[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
				op_list.push_back(input[i]);
				break;
			default:
				size_t j = i;
				int num = 0;
				while (j < input.size() && input[j] >= '0' && input[j] <= '9') {
					num = num * 10 + static_cast<int> (input[j] - '0');
					++ j;
				}
				i = j - 1;
				num_list.push_back(num);
				break;
			}
		}
		return diffWaysToCompute(0, op_list.size());
    }
    vector<int> diffWaysToCompute(size_t left, size_t right) {
		vector<int> answer_list;
		if (left > right) {
		}
		else if (left == right) {
			answer_list.push_back(num_list[left]);
		}
		else {
			for (size_t i = left; i < right; ++ i) {
				vector<int> left_list = diffWaysToCompute(left, i);
				vector<int> right_list = diffWaysToCompute(i + 1, right);
				for (size_t j = 0; j < left_list.size(); ++ j) {
					for (size_t k = 0; k < right_list.size(); ++ k) {
						int ans(0);
						switch (op_list[i]) {
						case '+':
							ans = left_list[j] + right_list[k];
							break;
						case '-':
							ans = left_list[j] - right_list[k];
							break;
						case '*':
							ans = left_list[j] * right_list[k];
							break;
						case '/':
							ans = left_list[j] / right_list[k];
							break;
						}
						//cout << "test " << left_list[j] << " " << op_list[i] << " " << right_list[k] << " = " << ans << endl;
						answer_list.push_back(ans);
					}
				}
			}
		}
		return answer_list;
	}
	vector<int> num_list;
	vector<char> op_list;
};