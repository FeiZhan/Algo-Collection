/*
 * @lc app=leetcode id=1160 lang=java
 *
 * [1160] Find Words That Can Be Formed by Characters
 */
class Solution {
    public int countCharacters(String[] words, String chars) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (char c : chars.toCharArray()) {
            charMap.put(c, charMap.getOrDefault(c, 0) + 1);
        }
        int count = 0;
        for (String word : words) {
            boolean flag = false;
            Map<Character, Integer> map = new HashMap<>();
            for (char c : word.toCharArray()) {
                map.put(c, map.getOrDefault(c, 0) + 1);
                if (!charMap.containsKey(c) || map.get(c) > charMap.get(c)) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                count += word.length();
            }
        }
        return count;
    }
}

