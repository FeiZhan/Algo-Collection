class Solution {
    public int maximumLength(String s) {
        int length = s.length();
        int left = 0;
        Map<Character, Integer> charCounts = new HashMap<>();
        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);
            if (i + 1 == length || c != s.charAt(i + 1)) {
                int count = Math.max(i - left + 1, charCounts.getOrDefault(c, 0));
                charCounts.put(c, count);
                left = i + 1;
            }
        }

        int result = 0;
        for (char c : charCounts.keySet()) {
            int charCount = charCounts.get(c);
            for (int i = charCount; i > result; i--) {
                int count = -1;
                int index = -1;
                String substring = new String(new char[i]).replace('\0', c);
                do {
                    count++;
                    index = s.indexOf(substring, index + 1);
                } while (index != -1 && count < 3);
                //System.out.println(c + " " + i + ":" + count + " " + index);
                if (count >= 3) {
                    result = i;
                    break;
                }
            }
        }

        return result > 0 ? result : -1;
    }
}