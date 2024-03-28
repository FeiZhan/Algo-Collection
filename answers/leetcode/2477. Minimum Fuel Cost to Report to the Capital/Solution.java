class Solution {
    public long minimumFuelCost(int[][] roads, int seats) {
        Map<Integer, List<Integer>> roadMap = new HashMap<>();
        for (int[] road : roads) {
            List<Integer> list = roadMap.getOrDefault(road[0], new LinkedList<>());
            list.add(road[1]);
            roadMap.put(road[0], list);
            list = roadMap.getOrDefault(road[1], new LinkedList<>());
            list.add(road[0]);
            roadMap.put(road[1], list);
        }

        Set<Integer> visited = new HashSet<>();
        return this.run(0, 0, visited, roadMap, seats);
    }

    private int run(int personNumber, int city, Set<Integer> visited, Map<Integer, List<Integer>> roadMap, int seatNumber) {
        if (visited.contains(city) || !roadMap.containsKey(city)) {
            return 0;
        }

        visited.add(city);
        int result = personNumber / seatNumber + (personNumber % seatNumber > 0 ? 1 : 0);
        //System.out.println(city + " " + personNumber + " " + result);
        List<Integer> list = roadMap.get(city);
        for (int next : list) {
            result += this.run(personNumber + 1, next, visited, roadMap, seatNumber);
        }

        return result;
    }
}