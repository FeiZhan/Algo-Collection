class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
		my_stack.push(number);
		if (min_stack.empty() || min_stack.top() >= number) {
			min_stack.push(number);
		}
    }

    int pop() {
        // write your code here
		int temp = my_stack.top();
		my_stack.pop();
		if (temp == min_stack.top()) {
			min_stack.pop();
		}
		return temp;
    }

    int min() {
        // write your code here
		return min_stack.top();
    }
	stack<int> my_stack;
	stack<int> min_stack;
};

