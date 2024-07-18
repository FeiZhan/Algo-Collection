class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        Map<Character, Integer> garbageMap = new HashMap<>();
        Map<Character, Integer> lastMap = new HashMap<>();
        for (int i = 0; i < garbage.length; i++) {
            for (char c : garbage[i].toCharArray()) {
                garbageMap.put(c, garbageMap.getOrDefault(c, 0) + 1);
                lastMap.put(c, i);
            }
        }

        int result = 0;
        for (char c : garbageMap.keySet()) {
            result += garbageMap.get(c);
            int last = lastMap.get(c);
            for (int i = 0; i < last; i++) {
                result += travel[i];
            }
        }

        return result;
    }
}