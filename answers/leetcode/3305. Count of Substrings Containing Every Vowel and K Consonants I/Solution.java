class Solution {
    public int countOfSubstrings(String word, int k) {
        Set<Character> VOWEL_SET = new HashSet<>();
        VOWEL_SET.add('a');
        VOWEL_SET.add('e');
        VOWEL_SET.add('i');
        VOWEL_SET.add('o');
        VOWEL_SET.add('u');

        int consonantCount = 0;
        int left = 0;
        int result = 0;
        Map<Character, Integer> vowelMap = new HashMap<>();
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            if (VOWEL_SET.contains(c)) {
                vowelMap.put(c, vowelMap.getOrDefault(c, 0) + 1);
            } else {
                consonantCount++;
                while (left <= i && consonantCount > k) {
                    char leftChar = word.charAt(left);
                    if (VOWEL_SET.contains(leftChar)) {
                        vowelMap.put(leftChar, vowelMap.get(leftChar) - 1);
                        if (vowelMap.get(leftChar) <= 0) {
                            vowelMap.remove(leftChar);
                        }
                    } else {
                        consonantCount--;
                    }
                    left++;
                }
            }
            if (consonantCount == k && vowelMap.size() == 5) {
                result++;
                int index = left;
                Map<Character, Integer> map = new HashMap<>(vowelMap);
                while (index <= i) {
                    char leftChar = word.charAt(index);
                    if (map.getOrDefault(leftChar, 0) <= 1) {
                        break;
                    }
                    map.put(leftChar, map.get(leftChar) - 1);
                    index++;
                    result++;
                }
            }
            //System.out.println(left + " - " + i + " " + c + ": " + consonantCount + " " + vowelMap.size() + ": " + result);
        }

        return result;
    }
}