import java.util.SortedMap;

class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int[] result = new int[nums.length - k + 1];
        Map<Integer, Integer> numberMap = new HashMap<>();
        SortedMap<Integer, Set<Integer>> countMap = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < nums.length; i++) {
            int number = nums[i];
            if (numberMap.containsKey(number)) {
                int count = numberMap.get(number);
                Set<Integer> set = countMap.get(count);
                set.remove(number);
            }
            int count = numberMap.getOrDefault(number, 0) + 1;
            numberMap.put(number, count);
            Set<Integer> set = countMap.getOrDefault(count, new HashSet<>());
            set.add(number);
            countMap.put(count, set);
            if (i >= k) {
                int oldNumber = nums[i - k];
                int oldCount = numberMap.get(oldNumber);
                set = countMap.get(oldCount);
                set.remove(oldNumber);
                oldCount--;
                numberMap.put(oldNumber, oldCount);
                set = countMap.getOrDefault(oldCount, new HashSet<>());
                set.add(oldNumber);
                countMap.put(oldCount, set);
            }
            if (i + 1 >= k) {
                int index = 1;
                for (Set<Integer> set1 : countMap.values()) {
                    List<Integer> list = new ArrayList<>(set1);
                    Collections.sort(list, Collections.reverseOrder());
                    for (int n : list) {
                        result[i - k + 1] += n * numberMap.get(n);
                        index++;
                        if (index > x) {
                            break;
                        }
                    }
                    if (index > x) {
                        break;
                    }
                }
            }
        }

        return result;
    }
}