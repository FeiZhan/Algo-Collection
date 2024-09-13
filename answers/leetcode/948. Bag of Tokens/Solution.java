class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int sum = 0;
        for (int token : tokens) {
            sum += token;
        }
        if (power >= sum) {
            return tokens.length;
        }
        
        Arrays.sort(tokens);
        if (power < tokens[0]) {
            return 0;
        }

        for (int i = tokens.length - 1; i >= 0; i--) {
            sum -= tokens[i];
            if (power >= sum) {
                return i + i - tokens.length + 1;
            }
            power += tokens[i];
            if (power >= sum) {
                return i + i - tokens.length;
            }
        }

        return 0;
    }
}