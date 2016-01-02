class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
		const int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const std::string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		int i = 0;
		std::string ans;
		while (num > 0)
		{
			int times = num / nums[i];
			num -= nums[i] * times;
			for (; times > 0; -- times)
			{
				ans += symbols[i];
			}
			++ i;
		}
		return ans;
    }
};
