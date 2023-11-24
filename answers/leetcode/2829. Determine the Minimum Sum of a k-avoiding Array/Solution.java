class Solution {
    public int minimumSum(int n, int k) {
        int number = 1;
        int result = 0;
        Set<Integer> numbers = new HashSet<>();

        while (n > 0) {
            if (!numbers.contains(k - number)) {
                result += number;
                numbers.add(number);
                n--;
            }
            number++;
        }

        return result;
    }
}