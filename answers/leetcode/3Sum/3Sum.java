class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> results = new ArrayList<List<Integer>>();
        Map<Integer, Integer> numMap = new HashMap<Integer, Integer>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        for (int num : numMap.keySet()) {
            if (0 == num && numMap.get(num) >= 3) {
                List<Integer> result = new ArrayList<Integer>();
                result.add(0);
                result.add(0);
                result.add(0);
                results.add(result);
            } else if (num != 0 && numMap.get(num) >= 2 && numMap.containsKey(- num * 2)) {
                List<Integer> result = new ArrayList<Integer>();
                result.add(num);
                result.add(num);
                result.add(- num * 2);
                results.add(result);
            }
            for (int num1 : numMap.keySet()) {
                int num2 = - num - num1;
                if (num < num1 && num1 < num2 && numMap.containsKey(num2)) {
                    List<Integer> result = new ArrayList<Integer>();
                    result.add(num);
                    result.add(num1);
                    result.add(num2);
                    results.add(result);
                }
            }
        }
        return results;
    }
}