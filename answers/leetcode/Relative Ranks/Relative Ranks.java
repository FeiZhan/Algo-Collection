class Solution {
    public String[] findRelativeRanks(int[] nums) {
        TreeMap<Integer, String> map = new TreeMap<Integer, String>(Collections.reverseOrder());
        for (int i = 0; i < nums.length; i++) {
           map.put(nums[i], null);
        }
        Iterator<Map.Entry<Integer, String>> iterator = map.entrySet().iterator();
        int rank = 1;
        while (iterator.hasNext()) {
            String value;
            switch (rank) {
                case 1:
                    value = "Gold Medal";
                    break;
                case 2:
                    value = "Silver Medal";
                    break;
                case 3:
                    value = "Bronze Medal";
                    break;
                default:
                    value = Integer.toString(rank);
                    break;
            }
            iterator.next().setValue(value);
            rank++;
        }
        String[] ranks = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            ranks[i] = map.get(nums[i]);
        }
        return ranks;
    }
}