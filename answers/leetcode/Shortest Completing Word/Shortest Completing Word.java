class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        Map<Character, Integer> license = new HashMap<>();
        for (char c : licensePlate.toCharArray()) {
            if (Character.isLetter(c)) {
                c = Character.toLowerCase(c);
                license.put(c, license.getOrDefault(c, 0) + 1);
            }
        }
        String result = null;
        for (String word : words) {
            if (result != null && word.length() >= result.length()) {
                continue;
            }
            Map<Character, Integer> temp = new HashMap<>(license);
            for (char c : word.toCharArray()) {
                if (temp.containsKey(c)) {
                    int count = temp.get(c) - 1;
                    if (count > 0) {
                        temp.put(c, count);
                    } else {
                        temp.remove(c);
                    }
                }
            }
            if (temp.size() == 0) {
                result = word;
            }
        }
        return result;
    }
}