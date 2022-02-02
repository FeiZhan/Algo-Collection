class Solution {
    public int[] findEvenNumbers(int[] digits) {
        Map<Integer, Integer> digitMap = new HashMap<>();
        for (int digit : digits) {
            digitMap.put(digit, digitMap.getOrDefault(digit, 0) + 1);
        }

        List<Integer> resultList = new LinkedList<>();
        dfs(0, digitMap, resultList);

        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }

        return result;
    }

    private void dfs(int number, Map<Integer, Integer> digitMap, List<Integer> resultList) {
        if (number >= 100) {
            if (number % 2 == 0) {
                resultList.add(number);
            }
            return;
        }

        Set<Integer> keySet = new HashSet<>(digitMap.keySet());
        for (int digit : keySet) {
            if (number == 0 && digit == 0) {
                continue;
            }

            int count = digitMap.get(digit);
            if (count > 1) {
                digitMap.put(digit, count - 1);
            } else {
                digitMap.remove(digit);
            }
            dfs(number * 10 + digit, digitMap, resultList);
            digitMap.put(digit, count);
        }
    }
}
//Runtime: 8 ms, faster than 78.43% of Java online submissions for Finding 3-Digit Even Numbers.
//Memory Usage: 42.7 MB, less than 41.65% of Java online submissions for Finding 3-Digit Even Numbers.
