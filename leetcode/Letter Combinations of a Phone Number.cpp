class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> ans;
		if (0 == digits.length())
		{
			ans.push_back("");
			return ans;
		}
		const std::string LETTERS[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		vector<string> last( letterCombinations(digits.substr(1)) );
		for (int i = 0; i < last.size(); ++ i)
		{
			int digit = static_cast<int>(digits[0] - '0');
			for (int j = 0; j < LETTERS[digit].length(); ++ j)
			{
				ans.push_back(LETTERS[digit][j] + last[i]);
			}
		}
		return ans;
    }
};
