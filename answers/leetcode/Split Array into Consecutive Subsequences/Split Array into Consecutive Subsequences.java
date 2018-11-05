class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer, List<Integer>> seqMap = new HashMap<>();
        for (int num : nums) {
            if (seqMap.containsKey(num - 1)) {
                List<Integer> list = seqMap.get(num - 1);
                int index = 0;
                for (int i = 0; i < list.size(); i++) {
                    if (list.get(i) < list.get(index)) {
                        index = i;
                    }
                }
                List<Integer> countList = seqMap.getOrDefault(num, new ArrayList<>());
                countList.add(list.get(index) + 1);
                seqMap.put(num, countList);
                list.remove(index);
                if (list.size() == 0) {
                    seqMap.remove(num - 1);
                } else {
                    seqMap.put(num - 1, list);
                }
            } else {
                List<Integer> countList = seqMap.getOrDefault(num, new ArrayList<>());
                countList.add(1);
                seqMap.put(num, countList);
            }
        }
        for (Map.Entry<Integer, List<Integer>> entry : seqMap.entrySet()) {
            //System.out.println("key: " + entry.getKey());
            for (int count : entry.getValue()) {
                //System.out.println(count);
                if (count < 3) {
                    return false;
                }
            }
        }
        return true;
    }
}