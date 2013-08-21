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
