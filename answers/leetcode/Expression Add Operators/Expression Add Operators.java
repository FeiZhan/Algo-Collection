class Solution {
    public List<String> addOperators(String num, int target) {
        List<String> results = new LinkedList<>();
        if (num == null || num.length() == 0) {
            return results;
        }
        this.dfs(0, num, (long) target, 0l, 0l, new StringBuilder(), results);
        return results;
    }
    
    private void dfs(int index, String num, long target, long previous, long multi, StringBuilder sb, List<String> results) {
        if (index >= num.length()) {
            if (target == 0) {
                results.add(sb.toString());
            }
            return;
        }
        
        for (int i = index; i < num.length(); i++) {
            if (num.charAt(index) == '0' && i > index) {
                break;
            }
            long number = Long.parseLong(num.substring(index, i + 1));
            StringBuilder sb1 = new StringBuilder(sb);
            if (sb1.length() > 0) {
                sb1.append("+");
            }
            sb1.append(number);
            this.dfs(i + 1, num, target - number, number, number, sb1, results);

            if (sb.length() > 0) {
                sb1 = new StringBuilder(sb);
                sb1.append("-").append(number);
                this.dfs(i + 1, num, target + number, -number, -number, sb1, results);

                sb1 = new StringBuilder(sb);
                sb1.append("*").append(number);
                long newNum = multi * number;
                this.dfs(i + 1, num, target + multi - newNum, number, newNum, sb1, results);
            }
        }
    }
}