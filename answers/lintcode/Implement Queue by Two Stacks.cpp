class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {
        // write your code here
		stack1.push(element);
    }
    
    int pop() {
        // write your code here
		int temp = top();
		stack2.pop();
		return temp;
    }

    int top() {
        // write your code here
		if (stack2.empty()) {
			while (! stack1.empty()) {
				int temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}
		return stack2.top();
    }
};

