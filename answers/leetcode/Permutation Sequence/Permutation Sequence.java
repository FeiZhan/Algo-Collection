class Solution {
    public String getPermutation(int n, int k) {
        int[] factorial = new int[n + 1];
        factorial[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }
        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            numbers.add(i + 1);
        }
        k--;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int index = k / factorial[n - i - 1];
            sb.append(numbers.get(index));
            numbers.remove(index);
            k -= index * factorial[n - i - 1];
        }
        return sb.toString();
    }
}