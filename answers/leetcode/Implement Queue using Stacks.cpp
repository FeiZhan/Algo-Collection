//@type Stack Design
//@result 17 / 17 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 1.02% of cpp submissions.

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        in_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        peek();
		out_stack.pop();
    }

    // Get the front element.
    int peek(void) {
        if (out_stack.empty()) {
			while (! in_stack.empty()) {
				int temp = in_stack.top();
				in_stack.pop();
				out_stack.push(temp);
			}
		}
        if (out_stack.empty()) {
			return INT_MIN;
		}
		else {
			return out_stack.top();
		}
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in_stack.empty() && out_stack.empty();
    }
	stack<int> in_stack;
	stack<int> out_stack;
};
