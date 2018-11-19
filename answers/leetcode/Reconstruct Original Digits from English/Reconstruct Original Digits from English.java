class Solution {

    private static final Map<Character, Integer> CHAR_MAP;

    static {
        Map<Character, Integer> charMap = new HashMap<>();
        charMap.put('z', 0);
        charMap.put('w', 2);
        charMap.put('x', 6);
        charMap.put('s', 7);
        charMap.put('g', 8);
        charMap.put('u', 4);
        charMap.put('f', 5);
        charMap.put('h', 3);
        charMap.put('i', 9);
        charMap.put('o', 1);
        CHAR_MAP = Collections.unmodifiableMap(charMap);
    }

    public String originalDigits(String s) {
        int[] counts = new int[10];
        for (char c : s.toCharArray()) {
            if (CHAR_MAP.containsKey(c)) {
                counts[CHAR_MAP.get(c)]++;
            }
        }
        counts[7] -= counts[6];
        counts[5] -= counts[4];
        counts[3] -= counts[8];
        counts[9] -= counts[8] + counts[5] + counts[6];
        counts[1] -= counts[0] + counts[2] + counts[4];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < counts[i]; j++) {
                sb.append(i);
            }
        }
        return sb.toString();
    }
}