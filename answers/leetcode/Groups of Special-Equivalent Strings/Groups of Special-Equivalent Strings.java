class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> groups = new HashSet<>();
        for (String str : A) {
            List<Character> even = new LinkedList<>();
            List<Character> odd = new LinkedList<>();
            for (int i = 0; i < str.length(); i++) {
                char c = str.charAt(i);
                if (i % 2 == 1) {
                    odd.add(c);
                } else {
                    even.add(c);
                }
            }
            Collections.sort(even);
            Collections.sort(odd);
            groups.add(even + "|" + odd);
        }
        return groups.size();
    }
}