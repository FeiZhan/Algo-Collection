class Solution {
    public int findKthPositive(int[] arr, int k) {
        Set<Integer> set = new HashSet<>();
        for (int number : arr) {
            set.add(number);
        }
        int count = 0;
        int number = 1;
        while (count < k) {
            if (!set.contains(number)) {
                count++;
                if (count == k) {
                    return number;
                }
            }
            number++;
        }
        return number;
    }
}