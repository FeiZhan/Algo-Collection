class Solution {
    public int[] numsSameConsecDiff(int N, int K) {
        Map<Integer, List<Integer>> dp = new HashMap<>();
        for (int i = 0; i <= 9; i++) {
            List<Integer> list = new LinkedList<>();
            list.add(i);
            dp.put(10 + i, list);
        }
        int tens = 1;
        for (int i = 2; i <= N; i++) {
            for (int j = 0; j <= 9; j++) {
                List<Integer> list = new LinkedList<>();
                if (j - K >= 0) {
                    List<Integer> rightList = dp.get((i - 1) * 10 + j - K);
                    for (int number : rightList) {
                        list.add(number + j * tens * 10);
                    }
                }
                if (K != 0 && j + K <= 9) {
                    List<Integer> rightList = dp.get((i - 1) * 10 + j + K);
                    for (int number : rightList) {
                        list.add(number + j * tens * 10);
                    }
                }
                dp.put(i * 10 + j, list);
            }
            tens *= 10;
        }
        List<Integer> resultList = new LinkedList<>();
        for (int i = (N == 1 ? 0 : 1); i <= 9; i++) {
            resultList.addAll(dp.get(N * 10 + i));
        }
        int[] result = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            result[i] = resultList.get(i);
        }
        return result;
    }
}