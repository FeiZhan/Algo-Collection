class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        return this.dfs(input, 0, input.length() - 1);
    }
    
    private List<Integer> dfs(String input, int start, int end) {
        List<Integer> results = new LinkedList<>();
        int number = 0;
        for (int i = start; i <= end; i++) {
            char c = input.charAt(i);
            if (!Character.isDigit(c)) {
                number = 0;
                List<Integer> leftList = this.dfs(input, start, i - 1);
                List<Integer> rightList = this.dfs(input, i + 1, end);
                for (int left : leftList) {
                    for (int right : rightList) {
                        int result = 0;
                        switch (c) {
                            case '+':
                                result = left + right;
                                break;
                            case '-':
                                result = left - right;
                                break;
                            case '*':
                                result = left * right;
                                break;
                            case '/':
                                result = left / right;
                                break;
                        }
                        results.add(result);
                    }
                }
            } else {
                number = number * 10 + Character. getNumericValue(c);
            }
        }
        if (results.size() == 0) {
            results.add(number);
        }
        return results;
    }
}