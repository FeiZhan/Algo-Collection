class Solution {
    private Map<Integer, List<String>> results = new HashMap<>();

    public Solution() {
        List<String> result = new LinkedList<>();
        result.add("");
        results.put(0, result);
    }

    public List<String> validStrings(int n) {
        if (!results.containsKey(n)) {
            List<String> previous = validStrings(n - 1);
            List<String> result = new LinkedList<>();
            for (String str : previous) {
                int length = str.length();
                if (length == 0 || str.charAt(length - 1) == '1') {
                    result.add(str + "0");
                }
                result.add(str + "1");
            }
            results.put(n, result);
        }

        return results.get(n);
    }
}