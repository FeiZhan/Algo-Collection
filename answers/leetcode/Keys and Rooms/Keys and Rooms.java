class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Set<Integer> visited = new HashSet<>();
        this.dfs(0, visited, rooms);
        return visited.size() == rooms.size();
    }

    private void dfs(int index, Set<Integer> visited, List<List<Integer>> rooms) {
        if (index < 0 || index >= rooms.size() || visited.contains(index)) {
            return;
        }
        visited.add(index);
        for (int room : rooms.get(index)) {
            this.dfs(room, visited, rooms);
        }
    }
}