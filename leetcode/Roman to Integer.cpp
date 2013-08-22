// copied from leetcode
class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (s.length() == 0)
		{
			return 0;
		}
		std::map<char, int> ROMAN;
		ROMAN['I'] = 1;
		ROMAN['V'] = 5;
		ROMAN['X'] = 10;
		ROMAN['L'] = 50;
		ROMAN['C'] = 100;
		ROMAN['D'] = 500;
		ROMAN['M'] = 1000;
		int sum = ROMAN[s[s.length() - 1]];
		for (int i = s.length() - 2; i >= 0; -- i)
		{
			if (ROMAN[s[i + 1]] <= ROMAN[s[i]])
			{
				sum += ROMAN[s[i]];
			} else
			{
				sum -= ROMAN[s[i]];
			}
		}
		return sum;
	}
};
