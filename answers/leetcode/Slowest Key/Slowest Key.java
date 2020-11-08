class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int start = 0;
        int slowest = 0;
        int index = 0;
        for (int i = 0; i < releaseTimes.length; i++) {
            int duration = releaseTimes[i] - start;
            if (duration > slowest || (duration == slowest && keysPressed.charAt(i) > keysPressed.charAt(index))) {
                slowest = duration;
                index = i;
            }
            start = releaseTimes[i];
        }
        return keysPressed.charAt(index);
    }
}