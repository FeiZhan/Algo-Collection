class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		long long nume = numerator;
		long long denom = denominator;
		string decimal;
		if (nume && ((nume < 0) ^ (denom < 0))) {
			decimal += '-';
		}
		// may overflow
		nume = std::abs(nume);
		denom = std::abs(denom);
		long long integer = nume / denom;
		nume -= denom * integer;
		if (0 == integer) {
			decimal += '0';
		}
		string int_str;
		while (integer > 0) {
			int_str += static_cast<char> (integer % 10 + '0');
			integer /= 10;
		}
		std::reverse(int_str.begin(), int_str.end());
		decimal += int_str;
		if (nume) {
			decimal += '.';
		}
		std::map<long long, int> decimal_map;
		while (nume) {
			// the same rem occurs
			if (decimal_map.end() != decimal_map.find(nume)) {
				decimal.insert(decimal_map[nume], 1, '(');
				decimal += ')';
				break;
			}
			decimal_map[nume] = decimal.length();
			int digit = nume * 10 / denom;
			decimal += static_cast<char> (digit + '0');
			nume = nume * 10 - denom * digit;
		}
		return decimal;
	}
};
