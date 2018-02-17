class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> times = new ArrayList<String>();
        for (int i = 0; i < 12; i++) {
            int count0 = Integer.bitCount(i);
            for (int j = 0; j < 60; j++) {
                if (count0 + Integer.bitCount(j) == num) {
                    times.add(String.format("%d:%02d", i, j));
                }
            }
        }
        return times;
    }
}