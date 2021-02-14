class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        Set<String> visited = new HashSet<>();
        this.dfs(s, visited, a, b);
        String smallest = s;
        for (String str : visited) {
            if (smallest.compareTo(str) > 0) {
                smallest = str;
            }
        }
        return smallest;
    }

    private void dfs(String current, Set<String> visited, int toAdd, int toRotate) {
        if (current == null || visited.contains(current)) {
            return;
        }

        visited.add(current);
        StringBuilder sb = new StringBuilder(current);
        for (int i = 1; i < current.length(); i += 2) {
            int digit = Character.getNumericValue(sb.charAt(i));
            digit = (digit + toAdd) % 10;
            sb.setCharAt(i, (char) (digit + '0'));
        }
        this.dfs(sb.toString(), visited, toAdd, toRotate);

        String rotated = current.substring(toRotate) + current.substring(0, toRotate);
        this.dfs(rotated, visited, toAdd, toRotate);
    }
}