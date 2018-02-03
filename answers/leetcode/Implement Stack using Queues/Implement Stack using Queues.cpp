//@type  Stack Design
//@result 16 / 16 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 0.58% of cpp submissions.
//@comment it is possible to use one queue to solve

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        in_que.push(x);
		while (in_que.size() > 1) {
			int temp = in_que.front();
			in_que.pop();
			out_que.push(temp);
		}
    }

    // Removes the element on top of the stack.
    void pop() {
		in_que.pop();
		while (! out_que.empty()) {
			int temp = out_que.front();
			out_que.pop();
			in_que.push(temp);
		}
		while (in_que.size() > 1) {
			int temp = in_que.front();
			in_que.pop();
			out_que.push(temp);
		}
    }

    // Get the top element.
    int top() {
		return in_que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return in_que.empty() && out_que.empty();
    }
	queue<int> in_que;
	queue<int> out_que;
};
