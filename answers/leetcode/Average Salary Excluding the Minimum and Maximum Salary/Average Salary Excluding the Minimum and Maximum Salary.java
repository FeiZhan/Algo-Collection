class Solution {
    public double average(int[] salary) {
        double sum = 0.0;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int number : salary) {
            sum += number;
            max = Math.max(max, number);
            min = Math.min(min, number);
        }
        return (sum - max - min) / (salary.length - 2);
    }
}