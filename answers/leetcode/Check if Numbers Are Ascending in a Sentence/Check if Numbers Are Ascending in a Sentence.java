class Solution {
    public boolean areNumbersAscending(String s) {
        int previous = Integer.MIN_VALUE;
        String[] words = s.split(" ");

        for (String word : words) {
            try {
                int number = Integer.parseInt(word);
                if (number <= previous) {
                    return false;
                }
                previous = number;
            } catch(NumberFormatException e) {
            }
        }

        return true;
    }
}