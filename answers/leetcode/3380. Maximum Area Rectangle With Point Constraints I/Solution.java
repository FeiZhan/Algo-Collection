import java.util.SortedMap;

class Solution {
    public int maxRectangleArea(int[][] points) {
        SortedMap<Integer, SortedMap<Integer, Integer>> xMap = new TreeMap<>();
        Map<Integer, Map<Integer, Integer>> yMap = new HashMap<>();
        for (int i = 0; i < points.length; i++) {
            SortedMap<Integer, Integer> sortedMap = xMap.getOrDefault(points[i][0], new TreeMap<>());
            sortedMap.put(points[i][1], i);
            xMap.put(points[i][0], sortedMap);
            Map<Integer, Integer> map = yMap.getOrDefault(points[i][1], new HashMap<>());
            map.put(points[i][0], i);
            yMap.put(points[i][1], map);
        }

        int result = -1;
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1] || !xMap.get(points[i][0]).containsKey(points[j][1]) || !yMap.get(points[i][1]).containsKey(points[j][0])) {
                    continue;
                }
                Set<Integer> pointSet = new HashSet<>();
                pointSet.add(i);
                pointSet.add(j);
                pointSet.add(xMap.get(points[i][0]).get(points[j][1]));
                pointSet.add(yMap.get(points[i][1]).get(points[j][0]));
                int minX = Math.min(points[i][0], points[j][0]);
                int maxX = Math.max(points[i][0], points[j][0]);
                int minY = Math.min(points[i][1], points[j][1]);
                int maxY = Math.max(points[i][1], points[j][1]);
                boolean flag = false;

                SortedMap<Integer, SortedMap<Integer, Integer>> subMap = xMap.subMap(minX, maxX + 1);
                for (SortedMap<Integer, Integer> map : subMap.values()) {
                    SortedMap<Integer, Integer> subMap1 = map.subMap(minY, maxY + 1);
                    for (int index : subMap1.values()) {
                        if (!pointSet.contains(index)) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                if (!flag) {
                    result = Math.max(result, (maxX - minX) * (maxY - minY));
                }
            }
        }

        return result;
    }
}