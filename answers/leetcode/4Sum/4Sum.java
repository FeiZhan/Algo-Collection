class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        List<Integer> numList = new ArrayList<>(numMap.keySet());
        Collections.sort(numList);
        Map<Integer, List<List<Integer>>> sumMap = new HashMap<>();
        for (int i = 0; i < numList.size(); i++) {
            int num = numList.get(i);
            if (numMap.get(num) > 1) {
                int sum = num + num;
                List<Integer> sumList = new LinkedList<>();
                sumList.add(num);
                sumList.add(num);
                List<List<Integer>> sumList1 = sumMap.getOrDefault(sum, new LinkedList<>());
                sumList1.add(sumList);
                sumMap.put(sum, sumList1);
            }
            for (int j = i + 1; j < numList.size(); j++) {
                int sum = num + numList.get(j);
                List<Integer> sumList = new LinkedList<>();
                sumList.add(num);
                sumList.add(numList.get(j));
                List<List<Integer>> sumList1 = sumMap.getOrDefault(sum, new LinkedList<>());
                sumList1.add(sumList);
                sumMap.put(sum, sumList1);
            }
        }
        List<List<Integer>> results = new LinkedList<>();
        for (Map.Entry<Integer, List<List<Integer>>> entry : sumMap.entrySet()) {
            int diff = target - entry.getKey();
            if (diff >= entry.getKey() && sumMap.containsKey(diff)) {
                List<List<Integer>> sums0 = entry.getValue();
                List<List<Integer>> sums1 = sumMap.get(diff);
                for (int i = 0; i < sums0.size(); i++) {
                    List<Integer> sum0 = sums0.get(i);
                    int sum01 = sum0.get(1);
                    for (int j = 0; j < sums1.size(); j++) {
                        List<Integer> sum1 = sums1.get(j);
                        int sum10 = sum1.get(0);
                        if (sum01 < sum10) {
                            List<Integer> result = new LinkedList<>();
                            result.addAll(sum0);
                            result.addAll(sum1);
                            results.add(result);
                        } else if (sum01 == sum10) {
                            int count = 2;
                            if (sum0.get(0) == sum01) {
                                count++;
                            }
                            if (sum10 == sum1.get(1)) {
                                count++;
                            }
                            if (numMap.get(sum01) >= count) {
                                List<Integer> result = new LinkedList<>();
                                result.addAll(sum0);
                                result.addAll(sum1);
                                results.add(result);
                            }
                        }
                    }
                }
            }
        }
        return results;
    }
}