import java.util.SortedMap;

class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        SortedMap<Integer, List<String>> heightMap = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < names.length; i++) {
            String name = names[i];
            int height = heights[i];
            List<String> nameList = heightMap.getOrDefault(height, new LinkedList<>());
            nameList.add(name);
            heightMap.put(height, nameList);
        }

        int i = 0;
        String[] result = new String[names.length];
        for (List<String> nameList : heightMap.values()) {
            for (String name : nameList) {
                result[i] = name;
                i++;
            }
        }

        return result;
    }
}