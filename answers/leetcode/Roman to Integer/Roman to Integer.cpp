//@result 3999 / 3999 test cases passed. Status: Accepted Runtime: 96 ms Submitted: 0 minutes ago You are here! Your runtime beats 5.90% of cpp submissions.

class Solution {
public:
    int romanToInt(string s) {
		std::map<string, int> roman_map;
		roman_map["I"] = 1;
		roman_map["IV"] = 4;
		roman_map["V"] = 5;
		roman_map["IX"] = 9;
		roman_map["X"] = 10;
		roman_map["XL"] = 40;
		roman_map["L"] = 50;
		roman_map["XC"] = 90;
		roman_map["C"] = 100;
		roman_map["CD"] = 400;
		roman_map["D"] = 500;
		roman_map["CM"] = 900;
		roman_map["M"] = 1000;
		size_t ptr = 0;
		int num = 0;
		while (ptr < s.length()) {
			std::map<string, int>::iterator it = roman_map.find(s.substr(ptr, 2));
			if (roman_map.end() != it) {
				num += it->second;
				ptr += 2;
				continue;
			}
			it = roman_map.find(s.substr(ptr, 1));
			if (roman_map.end() != it) {
				num += it->second;
				ptr += 1;
			}
		}
		return num;
    }
};
