//@result 17 / 17 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 0 minutes ago You are here! Your runtime beats 42.34% of cpp submissions.

class MinStack {
public:
	void push(int x) {
		my_stack.push(x);
		if (min_stack.empty() || x <= min_stack.top()) {
			min_stack.push(x);
		}
	}

	void pop() {
		if (! my_stack.empty()) {
			int val = my_stack.top();
			my_stack.pop();
			if (! min_stack.empty() && val == min_stack.top()) {
				min_stack.pop();
			}
		}
	}

	int top() {
		if (! my_stack.empty()) {
			return my_stack.top();
		}
		else {
			return INT_MAX;
		}
	}

	int getMin() {
		if (! min_stack.empty()) {
			return min_stack.top();
		}
		else {
			return INT_MAX;
		}
	}
	std::stack<int> my_stack, min_stack;
};
