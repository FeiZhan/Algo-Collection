class Solution {
    public boolean isPossibleToRearrange(String s, String t, int k) {
        int size = s.length() / k;
        Map<String, Integer> partitionMap = new HashMap<>();
        for (int i = 0; i < s.length(); i += size) {
            String sub = s.substring(i, i + size);
            partitionMap.put(sub, partitionMap.getOrDefault(sub, 0) + 1);
            sub = t.substring(i, i + size);
            partitionMap.put(sub, partitionMap.getOrDefault(sub, 0) - 1);
        }
        for (int count : partitionMap.values()) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
}