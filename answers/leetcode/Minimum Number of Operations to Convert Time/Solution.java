class Solution {
    public int convertTime(String current, String correct) {
        int minute = ((Character.getNumericValue(correct.charAt(0)) - Character.getNumericValue(current.charAt(0))) * 10
            + (Character.getNumericValue(correct.charAt(1)) - Character.getNumericValue(current.charAt(1)))) * 60
            + (Character.getNumericValue(correct.charAt(3)) - Character.getNumericValue(current.charAt(3))) * 10
            + (Character.getNumericValue(correct.charAt(4)) - Character.getNumericValue(current.charAt(4)));

        int result = minute / 60;
        minute %= 60;
        result += minute / 15;
        minute %= 15;
        result += minute / 5;
        minute %= 5;
        return result + minute;
    }
}
//Runtime: 1 ms, faster than 98.26% of Java online submissions for Minimum Number of Operations to Convert Time.
//Memory Usage: 42.5 MB, less than 57.24% of Java online submissions for Minimum Number of Operations to Convert Time.
