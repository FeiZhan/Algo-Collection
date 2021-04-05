class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> products = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int product = nums[i] * nums[j];
                products.put(product, products.getOrDefault(product, 0) + 1);
            }
        }

        int result = 0;
        for (int count : products.values()) {
            result += count * (count - 1) * 4;
        }

        return result;
    }
}