class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int result = 0;
        int sum = 0;
        for (int i = satisfaction.length - 1; i >= 0; i--) {
            if (sum + satisfaction[i] <= 0) {
                break;
            }
            result += sum + satisfaction[i];
            sum += satisfaction[i];
        }
        return result;
    }
}