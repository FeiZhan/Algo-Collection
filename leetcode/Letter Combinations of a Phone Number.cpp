//doing
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> ans;
		if (0 == digits.length())
		{
			return ans;
		}
		switch(digits[0])
		{
		case '0':
		case '1':
			ans.push_back("");
			break;
		case '2':
			ans.push_back("a");
			ans.push_back("b");
			ans.push_back("c");
			break;
		case '3':
			ans.push_back("d");
			ans.push_back("e");
			ans.push_back("f");
			break;
		case '4':
			ans.push_back("g");
			ans.push_back("h");
			ans.push_back("i");
			break;
		case '5':
			ans.push_back("j");
			ans.push_back("k");
			ans.push_back("l");
			break;
		case '6':
			ans.push_back("m");
			ans.push_back("n");
			ans.push_back("o");
			break;
		}
    }
};
