class Solution {
    public List<Integer> findPeaks(int[] mountain) {
        List<Integer> result = new LinkedList<>();
        for (int i = 1; i + 1 < mountain.length; i++) {
            if (mountain[i - 1] < mountain[i] && mountain[i] > mountain[i + 1]) {
                result.add(i);
            }
        }

        return result;
    }
}