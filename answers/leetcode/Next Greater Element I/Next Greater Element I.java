class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> greater = new HashMap<Integer, Integer>();
        Stack<Integer> stack = new Stack<Integer>();
        for (int num : nums2) {
            while (!stack.isEmpty() && stack.peek() < num) {
                int smaller = stack.pop();
                greater.put(smaller, num);
            }
            stack.push(num);
        }
        int[] result = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            result[i] = greater.getOrDefault(nums1[i], -1);
        }
        return result;
    }
}