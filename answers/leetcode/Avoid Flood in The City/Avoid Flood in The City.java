class Solution {
    public int[] avoidFlood(int[] rains) {
        int[] result = new int[rains.length];
        Map<Integer, Integer> full = new HashMap<>();
        for (int i = 0; i < rains.length; i++) {
            if (rains[i] != 0) {
                result[i] = -1;
                if (full.containsKey(rains[i])) {
                    boolean flag = false;
                    for (int j = full.get(rains[i]); j < i; j++) {
                        if (result[j] == 0) {
                            result[j] = rains[i];
                            flag = true;
                            break;
                        }
                    }
                    if (!flag) {
                        return new int[0];
                    }
                }
                full.put(rains[i], i);
            }
        }
        for (int i = 0; i < result.length; i++) {
            if (result[i] == 0) {
                result[i] = 1;
            }
        }
        return result;
    }
}