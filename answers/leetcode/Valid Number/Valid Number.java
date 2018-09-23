class Solution {
    public boolean isNumber(String s) {
        boolean ended = false;
        boolean haveDot = false;
        boolean haveE = false;
        boolean result = true;
        boolean started = false;
        int digits = 0;
        int leadingZeroes = 0;
        int sign = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            switch (c) {
                case ' ':
                    if (started && !ended) {
                        ended = true;
                    }
                    break;
                case '.':
                    if (haveDot || ended || haveE) {
                        result = false;
                    } else {
                        haveDot = true;
                        started = true;
                        leadingZeroes = 0;
                    }
                    break;
                case '+':
                case '-':
                    if (sign != 0 || started) {
                        result = false;
                    } else {
                        sign = c == '+' ? 1 : -1;
                        started = true;
                    }
                    break;
                case 'e':
                    if (haveE || ended || digits == 0) {
                        result = false;
                    } else {
                        haveE = true;
                        haveDot = false;
                        started = false;
                        digits = 0;
                        leadingZeroes = 0;
                        sign = 0;
                    }
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    if (ended) {
                        result = false;
                    } else {
                        if (digits == leadingZeroes && c == '0') {
                            leadingZeroes++;
                        }
                        digits++;
                        started = true;
                    }
                    break;
                default:
                    result = false;
            }
            if (!result) {
                break;
            }
        }
        if (!result || !started || digits == 0) {
            return false;
        } else {
            return true;
        }
    }
}