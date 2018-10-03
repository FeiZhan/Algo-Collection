class Solution {
    public int thirdMax(int[] nums) {
        List<Integer> maxList = new ArrayList<>();
        for (int num : nums) {
            for (int i = 0; i < 3; i++) {
                if (maxList.size() > i && num > maxList.get(i)) {
                    int temp = maxList.get(i);
                    maxList.set(i, num);
                    num = temp;
                } else if (maxList.size() > i && num == maxList.get(i)) {
                    break;
                } else if (maxList.size() <= i) {
                    maxList.add(num);
                    break;
                }
            }
        }
        return maxList.size() >= 3 ? maxList.get(2) : maxList.get(0);
    }
}