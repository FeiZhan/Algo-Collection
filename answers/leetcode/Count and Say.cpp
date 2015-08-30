class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		string ans = "1";
		stack<char> buf;
		for (int i = 1; i < n; ++ i)
		{
			for (int j = ans.size() - 1; j >=0;)
			{
				char lab = ans[j];
				buf.push(lab);
				int ct;
				for (ct = 0; lab == ans[j] && j >= 0; -- j, ++ ct)
				{}
				do {
					buf.push(ct % 10 + '0');
					ct /= 10;
				} while (ct > 0);
			}
			ans.clear();
			while (! buf.empty())
			{
				ans += buf.top();
				buf.pop();
			}
		}
		return ans;
    }
};

// 2014-12-18
class Solution {
public:
    string countAndSay(int n) {
		string ans("1");
		for (int i = 0; i < n - 1; ++ i) {
			string new_ans;
			int count = 1;
			for (size_t j = 1; j <= ans.size(); ++ j) {
				if (ans.size() == j) {
					new_ans += static_cast<char> (count + '0');
					new_ans += ans[j - 1];
				}
				else if (ans[j] == ans[j - 1]) {
					++ count;
				}
				else {
					new_ans += static_cast<char> (count + '0');
					new_ans += ans[j - 1];
					count = 1;
				}
			}
			ans = new_ans;
		}
		return ans;
    }
};
