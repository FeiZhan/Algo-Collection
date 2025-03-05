class Solution {
    public int totalFruit(int[] fruits) {
        int left = 0;
        int result = 0;
        Map<Integer, Integer> countMap = new HashMap<>();
        for (int i = 0; i < fruits.length; i++) {
            int fruit = fruits[i];
            countMap.put(fruit, countMap.getOrDefault(fruit, 0) + 1);
            while (countMap.size() > 2) {
                int leftFruit = fruits[left];
                countMap.put(leftFruit, countMap.get(leftFruit) - 1);
                if (countMap.get(leftFruit) == 0) {
                    countMap.remove(leftFruit);
                }
                left++;
            }
            result = Math.max(result, i - left + 1);
        }

        return result;
    }
}