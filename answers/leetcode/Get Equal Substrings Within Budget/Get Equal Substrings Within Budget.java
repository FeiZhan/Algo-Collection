class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int cost = 0;
        int left = 0;
        int result = 0;
        for (int i = 0; i < s.length() && i < t.length(); i++) {
            cost += Math.abs(s.charAt(i) - t.charAt(i));
            while (cost > maxCost && left <= i) {
                cost -= Math.abs(s.charAt(left) - t.charAt(left));
                left++;
            }
            result = Math.max(result, i - left + 1);
            System.out.println(left + " " + i + ": " + cost + " " + result);
        }
        return result;
    }
}