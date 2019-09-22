/*
 * @lc app=leetcode id=1154 lang=java
 *
 * [1154] Day of the Year
 */
class Solution {
    private static List<Integer> DAYS_BEFORE_MONTH;

    static {
        DAYS_BEFORE_MONTH = new ArrayList<>();
        int[] DAYS_IN_MONTH = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sum = 0;
        for (int days : DAYS_IN_MONTH) {
            DAYS_BEFORE_MONTH.add(sum);
            sum += days;
        }
    }

    public int dayOfYear(String date) {
        String[] splitDate = date.split("-");
        int year = Integer.parseInt(splitDate[0]);
        int month = Integer.parseInt(splitDate[1]);
        int result = DAYS_BEFORE_MONTH.get(month - 1);
        if (month > 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))) {
            result++;
        }
        return result + Integer.parseInt(splitDate[2]);
    }
}

