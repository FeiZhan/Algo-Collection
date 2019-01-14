class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] counts = new int[26];
        for (char task : tasks) {
            counts[(int)(task - 'A')]++;
        }
        Arrays.sort(counts);
        int maxIdle = counts[25] - 1;
        int totalIdle = maxIdle * n;
        for (int i = 24; i >= 0; i--) {
            totalIdle -= Math.min(maxIdle, counts[i]);
        }
        return tasks.length + (totalIdle > 0 ? totalIdle : 0);
    }
}