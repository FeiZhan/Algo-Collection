//@result Accepted Total Runtime: 11 ms 100% test cases passed.

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
		if (n > fib_list.size()) {
			if (fib_list.size() == 0) {
				fib_list.push_back(0);
			}
			if (1 == fib_list.size()) {
				fib_list.push_back(1);
			}
			for (size_t i = fib_list.size(); i <= n + 1; ++ i) {
				fib_list.push_back(fibonacci(i) + fibonacci(i - 1));
			}
		}
		return fib_list[n - 1];
    }
	vector<int> fib_list;
};

