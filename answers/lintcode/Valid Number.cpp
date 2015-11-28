class Solution {
public:
    enum Status {
        INVALID = -1,
        INITIAL = 0,
        DIGIT,
        DOT,
        SIGN,
        NUM_DOT,
        EXPONENT,
        EXP_SIGN,
        EXP_NUM,
        SPACE
    };
    enum InputType {
        INPUT_INVALID,
        INPUT_SPACE,
        INPUT_SIGN,
        INPUT_DIGIT,
        INPUT_DOT,
        INPUT_EXPONENT
    };
    Status table[9][6] = {
        // INPUT_INVALID    INPUT_SPACE     INPUT_SIGN  INPUT_DIGIT     INPUT_DOT   INPUT_EXPONENT
        {INVALID,            INITIAL,        SIGN,       DIGIT,          DOT,        INVALID},    // INITIAL
        {INVALID,            SPACE,          INVALID,    DIGIT,          NUM_DOT,    EXPONENT},   // DIGIT
        {INVALID,            INVALID,        INVALID,    NUM_DOT,        INVALID,    INVALID},    // DOT
        {INVALID,            INVALID,        INVALID,    DIGIT,          DOT,        INVALID},    // SIGN
        {INVALID,            SPACE,          INVALID,    NUM_DOT,        INVALID,    EXPONENT},   // NUM_DOT
        {INVALID,            INVALID,        EXP_SIGN,   EXP_NUM,        INVALID,    INVALID},    // EXPONENT
        {INVALID,            INVALID,        INVALID,    EXP_NUM,        INVALID,    INVALID},    // EXP_SIGN
        {INVALID,            SPACE,          INVALID,    EXP_NUM,        INVALID,    INVALID},    // EXP_NUM
        {INVALID,            SPACE,          INVALID,    INVALID,        INVALID,    INVALID}    // SPACE
    };
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string& s) {
        // Write your code here
        Status status = INITIAL;
        for (size_t i = 0; i < s.length(); ++ i) {
            InputType input = INPUT_INVALID;
            if (s[i] == ' ') input = INPUT_SPACE;
            else if (s[i] == '+' || s[i] == '-') input = INPUT_SIGN;
            else if (isdigit(s[i])) input = INPUT_DIGIT;
            else if (s[i] == '.') input = INPUT_DOT;
            else if (s[i] == 'e' || s[i] == 'E') input = INPUT_EXPONENT;
            status = table[status][input];
            if (status == INVALID) return false;
        }
        return status == DIGIT || status == NUM_DOT || status == EXP_NUM || status == SPACE;
    }
};
