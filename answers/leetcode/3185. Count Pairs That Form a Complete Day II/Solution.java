class Solution {
    public long countCompleteDayPairs(int[] hours) {
        Map<Integer, Long> hourMap = new HashMap<>();
        for (int hour : hours) {
            hour %= 24;
            hourMap.put(hour, hourMap.getOrDefault(hour, 0l) + 1l);
        }

        long zero = hourMap.getOrDefault(0, 0l);
        long twelve = hourMap.getOrDefault(12, 0l);
        long result = (zero - 1l) * zero + (twelve - 1l) * twelve;
        for (int hour : hourMap.keySet()) {
            if (hour == 0 || hour == 12) {
                continue;
            }
            result += hourMap.get(hour) * hourMap.getOrDefault(24 - hour, 0l);
        }

        return result / 2l;
    }
}