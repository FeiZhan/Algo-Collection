class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> times = timePoints.stream()
            .map(s -> {
                int[] time = Arrays.stream(s.split(":"))
                    .mapToInt(Integer::parseInt)
                    .toArray();
                return time[0] * 60 + time[1];
            }).sorted().collect(Collectors.toList());
        times.add(times.get(0) + 24 * 60);
        int minDiff = Integer.MAX_VALUE;
        for (int i = 1; i < times.size(); i++) {
            minDiff = Math.min(minDiff, times.get(i) - times.get(i - 1));
        }
        return minDiff;
    }
}