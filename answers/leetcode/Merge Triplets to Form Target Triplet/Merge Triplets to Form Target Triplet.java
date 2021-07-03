class Solution {
    public boolean mergeTriplets(int[][] triplets, int[] target) {
        List<List<Integer>> lists = new LinkedList<>();

        for (int[] triplet : triplets) {
            boolean flag = true;
            List<Integer> list = new LinkedList<>();
            for (int i = 0; i < triplet.length; i++) {
                if (triplet[i] > target[i]) {
                    flag = false;
                    break;
                }
                list.add(triplet[i]);
            }
            if (flag) {
                lists.add(list);
            }
        }

        for (int i = 0; i < target.length; i++) {
            int max = 0;
            for (List<Integer> list : lists) {
                max = Math.max(max, list.get(i));
            }
            if (max < target[i]) {
                return false;
            }
        }

        return true;
    }
}