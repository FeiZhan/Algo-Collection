class Solution {
    public int numTimesAllBlue(int[] flips) {
        int result = 0;
        List<Integer> leftList = new ArrayList<>();
        Set<Integer> oneSet = new HashSet<>();
        for (int i = 0; i < flips.length; i++) {
            oneSet.add(flips[i]);
            leftList.add(i + 1);
            for (int j = 0; j < leftList.size(); j++) {
                if (oneSet.contains(leftList.get(j))) {
                    leftList.remove(j);
                    j--;
                } else {
                    break;
                }
            }
            result += leftList.isEmpty() ? 1 : 0;
        }

        return result;
    }
}