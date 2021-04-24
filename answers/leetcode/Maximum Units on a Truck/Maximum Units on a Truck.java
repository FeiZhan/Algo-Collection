import java.util.SortedMap;

class Solution {
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        SortedMap<Integer, Integer> boxes = new TreeMap<>(Collections.reverseOrder());
        for (int[] boxType : boxTypes) {
            boxes.put(boxType[1], boxes.getOrDefault(boxType[1], 0) + boxType[0]);
        }

        int unitCount = 0;
        while (truckSize > 0 && boxes.size() > 0) {
            int units = boxes.firstKey();
            int count = boxes.get(units);
            unitCount += units * Math.min(truckSize, count);
            truckSize -= count;
            boxes.remove(units);
        }

        return unitCount;
    }
}