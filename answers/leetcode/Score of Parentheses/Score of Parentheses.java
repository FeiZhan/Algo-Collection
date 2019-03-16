class Solution {
    public int scoreOfParentheses(String S) {
        return S != null ? this.scoreOfParentheses(S, 0, S.length() - 1) : 0;
    }
    
    private int scoreOfParentheses(String str, int left, int right) {
        int score = 0;
        if (left <= right) {
            if (left + 1 == right) {
                score = 1;
            } else {
                int count = 0;
                int index = left;
                int previous = left;
                while (index <= right) {
                    if (str.charAt(index) == '(') {
                        count++;
                    } else {
                        count--;
                    }
                    if (count == 0 && (previous != left || index != right)) {
                        score += this.scoreOfParentheses(str, previous, index);
                        previous = index + 1;
                    }
                    index++;
                }
                if (score == 0) {
                    score = 2 * this.scoreOfParentheses(str, left + 1, right - 1);
                }
            }
        }
        //System.out.println(left + "-" + right + " " + score);
        return score;
    }
}