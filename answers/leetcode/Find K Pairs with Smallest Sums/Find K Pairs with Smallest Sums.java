class Solution {
    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<int[]> results = new LinkedList<>();
        if (nums1 == null || nums1.length == 0 || nums2 == null || nums2.length == 0 || k <= 0) {
            return results;
        }
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> nums1[a[0]] + nums2[a[1]] - nums1[b[0]] - nums2[b[1]]);
        for (int i = 0; i < nums1.length; i++) {
            queue.add(new int[] {i, 0});
        }
        while (!queue.isEmpty() && results.size() < k) {
            int[] indexes = queue.poll();
            int[] pair = new int[] {nums1[indexes[0]], nums2[indexes[1]]};
            //System.out.println(indexes[0] + " " + indexes[1] + ": " + pair[0] + " " + pair[1]);
            results.add(pair);
            if (indexes[1] + 1 < nums2.length) {
                queue.add(new int[] {indexes[0], indexes[1] + 1});
            }
        }
        return results;
    }
}