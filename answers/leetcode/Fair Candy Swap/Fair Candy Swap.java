class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int aSum = 0;
        for (int candy : A) {
            aSum += candy;
        }
        int bSum = 0;
        Set<Integer> bSet = new HashSet<>();
        for (int candy : B) {
            bSum += candy;
            bSet.add(candy);
        }
        int difference = (aSum - bSum) / 2;
        int[] result = new int[2];
        for (int candy : A) {
            if (bSet.contains(candy - difference)) {
                result[0] = candy;
                result[1] = candy - difference;
                break;
            }
        }
        return result;
    }
}