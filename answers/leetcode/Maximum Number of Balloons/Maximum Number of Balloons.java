/*
 * @lc app=leetcode id=1189 lang=java
 *
 * [1189] Maximum Number of Balloons
 */
class Solution {
    public int maxNumberOfBalloons(String text) {
        Map<Character, Integer> chars = new HashMap<>();
        for (char c : text.toCharArray()) {
            chars.put(c, chars.getOrDefault(c, 0) + 1);
        }
        int count = chars.getOrDefault('a', 0);
        count = Math.min(count, chars.getOrDefault('b', 0));
        count = Math.min(count, chars.getOrDefault('l', 0) / 2);
        count = Math.min(count, chars.getOrDefault('o', 0) / 2);
        count = Math.min(count, chars.getOrDefault('n', 0));
        return count;
    }
}

