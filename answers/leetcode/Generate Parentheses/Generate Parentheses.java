class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>();
        this.generateParenthesis(n, result, "", 0, 0);
        return result;
    }

    private void generateParenthesis(int max, List<String> result, String current, int left, int right) {
        if (left >= max && right >= max) {
            result.add(current);
            return;
        }
        if (left < max) {
            this.generateParenthesis(max, result, current + "(", left + 1, right);
        }
        if (right < left) {
            this.generateParenthesis(max, result, current + ")", left, right + 1);
        }
    }
}