class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        int startTime1 = getTime(event1[0]);
        int endTime1 = getTime(event1[1]);
        int startTime2 = getTime(event2[0]);
        int endTime2 = getTime(event2[1]);

        return (startTime2 <= startTime1 && startTime1 <= endTime2) || (startTime1 <= startTime2 && startTime2 <= endTime1);
    }

    private int getTime(String str) {
        String[] time = str.split(":");
        return Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
    }
}
//Runtime: 3 ms, faster than 30.00% of Java online submissions for Determine if Two Events Have Conflict.
//Memory Usage: 41.8 MB, less than 10.00% of Java online submissions for Determine if Two Events Have Conflict.
