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
