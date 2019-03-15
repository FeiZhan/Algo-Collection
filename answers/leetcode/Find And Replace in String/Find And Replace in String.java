import java.util.SortedMap;

class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        SortedMap<Integer, Integer> indexMap = new TreeMap<>();
        for (int i = 0; i < indexes.length; i++) {
            if (S.substring(indexes[i], indexes[i] + sources[i].length()).equals(sources[i])) {
                indexMap.put(indexes[i], i);
            }
        }
        int count = 0;
        StringBuilder sb = new StringBuilder(S);
        for (SortedMap.Entry<Integer, Integer> entry : indexMap.entrySet()) {
            //System.out.println(entry.getKey() + ": " + entry.getValue());
            int length = sources[entry.getValue()].length();
            int start = entry.getKey() + count;
            sb.replace(start, start + length, targets[entry.getValue()]);
            count += targets[entry.getValue()].length() - length;
        }
        return sb.toString();
    }
}