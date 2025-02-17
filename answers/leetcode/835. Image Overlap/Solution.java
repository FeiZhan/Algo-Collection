class Solution {
    public int largestOverlap(int[][] img1, int[][] img2) {
        int height = img1.length;
        int width = img1[0].length;
        List<List<Integer>> ones1 = new ArrayList<>();
        List<List<Integer>> ones2 = new ArrayList<>();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (img1[i][j] == 1) {
                    List<Integer> list = new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    ones1.add(list);
                }
                if (img2[i][j] == 1) {
                    List<Integer> list = new ArrayList<>();
                    list.add(i);
                    list.add(j);
                    ones2.add(list);
                }
            }
        }
        Map<Integer, Integer> vectorMap = new HashMap<>();
        for (List<Integer> one1 : ones1) {
            for (List<Integer> one2 : ones2) {
                int vector = (one1.get(0) - one2.get(0)) * 1000 + one1.get(1) - one2.get(1);
                vectorMap.put(vector, vectorMap.getOrDefault(vector, 0) + 1);
            }
        }
        int result = 0;
        for (int count : vectorMap.values()) {
            result = Math.max(result, count);
        }

        return result;
    }
}