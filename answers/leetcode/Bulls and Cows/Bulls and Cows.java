class Solution {
    public String getHint(String secret, String guess) {
        Map<Character, Integer> secretMap = new HashMap<>();
        for (char c : secret.toCharArray()) {
            secretMap.put(c, secretMap.getOrDefault(c, 0) + 1);
        }
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.length() && i < guess.length(); i++) {
            char c = guess.charAt(i);
            if (secret.charAt(i) == c) {
                bulls++;
            }
            if (secretMap.containsKey(c) && secretMap.get(c) > 0) {
                cows++;
                secretMap.put(c, secretMap.get(c) - 1);
            }
        }
        return bulls + "A" + (cows - bulls) + "B";
    }
}