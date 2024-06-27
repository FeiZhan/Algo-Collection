class Solution {
    public boolean canSortArray(int[] nums) {
        Map<Integer, Integer> setMap = new HashMap<>();
        for (int number : nums) {
            int temp = number;
            int count = 0;
            while (temp > 0) {
                count += temp % 2;
                temp /= 2;
            }
            setMap.put(number, count);
        }

        int previousMax = -1;
        int currentSet = -1;
        int currentMin = Integer.MAX_VALUE;
        int currentMax = -1;
        for (int number : nums) {
            if (setMap.get(number) != currentSet) {
                if (previousMax > currentMin) {
                    return false;
                }
                previousMax = currentMax;
                currentSet = setMap.get(number);
                currentMin = number;
                currentMax = number;
            } else {
                currentMin = Math.min(currentMin, number);
                currentMax = Math.max(currentMax, number);
            }
        }

        return previousMax <= currentMin;
    }
}