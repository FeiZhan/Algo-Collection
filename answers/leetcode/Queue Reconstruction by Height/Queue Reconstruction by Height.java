class Solution {
    public int[][] reconstructQueue(int[][] people) {
        SortedMap<Integer, SortedSet<Integer>> counts = new TreeMap<>();
        for (int i = 0; i < people.length; i++) {
            SortedSet<Integer> countSet = counts.getOrDefault(people[i][1], new TreeSet<>());
            countSet.add(i);
            counts.put(people[i][1], countSet);
        }
        List<Integer> line = new LinkedList<>();
        for (SortedSet<Integer> countSet : counts.values()) {
            for (int index : countSet) {
                int count = 0;
                int[] person = people[index];
                for (int i = 0; i < line.size(); i++) {
                    if (people[line.get(i)][0] >= person[0]) {
                        count++;
                    }
                    if (count > person[1]) {
                        line.add(i, index);
                        count = -1;
                        break;
                    }
                }
                if (count >= 0) {
                    line.add(index);
                }
            }
        }
        int[][] result = new int[people.length][2];
        for (int i = 0; i < line.size(); i++) {
            int[] person = people[line.get(i)];
            result[i][0] = person[0];
            result[i][1] = person[1];
        }
        return result;
    }
}
