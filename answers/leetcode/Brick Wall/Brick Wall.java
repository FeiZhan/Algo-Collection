class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> brickMap = new HashMap<>();
        for (int i = 0; i < wall.size(); i++) {
            int sum = 0;
            for (int j = 0; j + 1 < wall.get(i).size(); j++) {
                sum += wall.get(i).get(j);
                brickMap.put(sum, brickMap.getOrDefault(sum, 0) + 1);
            }
        }
        /*for (Map.Entry<Integer, Integer> entry : brickMap.entrySet()) {
            System.out.println(entry.getKey() + " " + entry.getValue());
        }*/
        return wall.size() - (brickMap.size() > 0 ? Collections.max(brickMap.values()) : 0);
    }
}