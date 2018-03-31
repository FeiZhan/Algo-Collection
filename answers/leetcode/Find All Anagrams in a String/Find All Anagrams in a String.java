class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        Map<Character, Integer> letters = new HashMap<Character, Integer>();
        for (char c : p.toCharArray()) {
            letters.put(c, letters.getOrDefault(c, 0) + 1);
        }
        List<Integer> anagrams = new ArrayList<Integer>();
        for (int i = 0; i < s.length(); i++) {
            if (i >= p.length()) {
                char left = s.charAt(i - p.length());
                letters.put(left, letters.getOrDefault(left, 0) + 1);
                if (letters.get(left) == 0) {
                    letters.remove(left);
                }
            }
            char right = s.charAt(i);
            letters.put(right, letters.getOrDefault(right, 0) - 1);
            if (letters.get(right) == 0) {
                letters.remove(right);
            }
            if (i + 1 >= p.length() && letters.size() == 0) {
                anagrams.add(i - p.length() + 1);
            }
            //System.out.println(right + " " + letters.size());
        }
        return anagrams;
    }
}