class Solution {

    private static final Map<Character, Integer> CROAK = new HashMap<>();

    static {
        CROAK.put('c', 0);
        CROAK.put('r', 1);
        CROAK.put('o', 2);
        CROAK.put('a', 3);
        CROAK.put('k', 4);
    }

    public int minNumberOfFrogs(String croakOfFrogs) {
        int current = 0;
        int max = 0;
        Map<Integer, Integer> charCounts = new HashMap<>();
        for (char c : croakOfFrogs.toCharArray()) {
            int index = CROAK.get(c);
            if (index > 0) {
                int count1 = charCounts.getOrDefault(index - 1, 0);
                if (count1 <= 0) {
                    return -1;
                }
                charCounts.put(index - 1, count1 - 1);
            }
            charCounts.put(index, charCounts.getOrDefault(index, 0) + 1);
            if (index == 0) {
                current++;
            } else if (index == 4) {
                current--;
            }
            max = Math.max(max, current);
        }
        for (int i = 0; i < 4; i++) {
            if (charCounts.getOrDefault(i, 0) > 0) {
                return -1;
            }
        }
        return max;
    }
}