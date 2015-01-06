// finite automata
class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		enum InputType
		{
			INVALID,
			SPACE,
			SIGN,
			DIGIT,
			DOT,
			EXPONENT,
			NUM_INPUTS	// 6
		};
		int transTable[][NUM_INPUTS] = {
			-1, 0, 3, 1, 2, -1,
			-1, 8, -1, 1, 4, 5,
			-1, -1, -1, 4, -1, -1,
			-1, -1, -1, 1, 2, -1,
			-1, 8, -1, 4, -1, 5,
			-1, -1, 6, 7, -1, -1,
			-1, -1, -1, 7, -1, -1,
			-1, 8, -1, 7, -1, -1,
			-1, 8, -1, -1, -1, -1,
		};
		int state = 0;
		while (*s != '\0')
		{
			InputType inputType = INVALID;
			if (isspace(*s))
			{
				inputType = SPACE;
			}
			else if ('+' == *s || '-' == *s)
			{
				inputType = SIGN;
			}
			else if (isdigit(*s))
			{
				inputType = DIGIT;
			}
			else if ('.' == *s)
			{
				inputType = DOT;
			}
			else if ('e' == *s || *s == 'E')
			{
				inputType = EXPONENT;
			}
			state = transTable[state][inputType];
			if (-1 == state)
			{
				return false;
			} else
			{
				++ s;
			}
		}
		return 1 == state || 4 == state || 7 == state || 8 == state;
    }
};


// 2015-01-06
class Solution {
public:
	bool isNumber(const char *s) {
		if (NULL == s) {
			return false;
		}
		while (isspace(*s)) {
			++ s;
		}
		if ('+' == *s || '-' == *s) {
			++ s;
		}
		bool e_flag = false;
		bool dot_flag = false;
		bool first_part = false;
		bool second_part = false;
		bool space_flag = false;
		while (*s) {
			if ('.' == *s) {
				if (dot_flag || e_flag || space_flag) {
					return false;
				}
				else {
					dot_flag = true;
				}
			}
			else if ('e' == *s || 'E' == *s) {
				if (e_flag || ! first_part || space_flag) {
					return false;
				}
				else {
					e_flag = true;
				}
			}
			else if (isdigit(*s)) {
				if (space_flag) {
					return false;
				}
				if (! e_flag) {
					first_part = true;
				}
				else {
					second_part = true;
				}
			}
			else if ('+' == *s || '-' == *s) {
				if (space_flag) {
					return false;
				}
				if (!e_flag || !('e' == *(s - 1) || 'E' == *(s - 1))) {
					return false;
				}
			}
			else if (isspace(*s)) {
				space_flag = true;
			}
			else {
				return false;
			}
			++ s;
		}
		if (!first_part) {
			return false;
		}
		else if (e_flag && !second_part) {
			return false;
		}
		return true;
	}
};