import java.util.SortedMap;

/*
 * @lc app=leetcode id=1170 lang=java
 *
 * [1170] Compare Strings by Frequency of the Smallest Character
 */
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        SortedMap<Integer, Integer> freqMap = new TreeMap<>(Collections.reverseOrder());
        for (String word : words) {
            int count = this.getFrequency(word);
            freqMap.put(count, freqMap.getOrDefault(count, 0) + 1);
        }
        int count = 0;
        SortedMap<Integer, Integer> countMap = new TreeMap<>();
        for (int freq : freqMap.keySet()) {
            count += freqMap.get(freq);
            countMap.put(freq, count);
        }
        List<Integer> result = new LinkedList<>();
        for (String query : queries) {
            int freq = this.getFrequency(query);
            SortedMap<Integer, Integer> tailMap = countMap.tailMap(freq + 1);
            if (tailMap.isEmpty()) {
                result.add(0);
            } else {
                result.add(tailMap.get(tailMap.firstKey()));
            }
        }
        int[] results = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            results[i] = result.get(i);
        }
        return results;
    }

    private int getFrequency(String word) {
        char smallest = 'z';
        int count = 0;
        for (char c : word.toCharArray()) {
            if (c < smallest) {
                smallest = c;
                count = 1;
            } else if (c == smallest) {
                count++;
            }
        }
        //System.out.println(word + " " + count);
        return count;
    }
}

