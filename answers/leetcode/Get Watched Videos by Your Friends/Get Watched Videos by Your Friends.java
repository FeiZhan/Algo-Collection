class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        Map<Integer, Integer> levels = new HashMap<>();
        this.dfs(id, 0, levels, friends);
        Map<String, Integer> counts = new HashMap<>();
        for (int i = 0; i < watchedVideos.size(); i++) {
            if (levels.getOrDefault(i, -1) == level) {
                for (String video : watchedVideos.get(i)) {
                    counts.put(video, counts.getOrDefault(video, 0) + 1);
                }
            }
        }
        List<String> result = new ArrayList<>(counts.keySet());
        result.sort((v0, v1) -> {
            if (counts.get(v0) != counts.get(v1)) {
                return counts.get(v0) - counts.get(v1);
            } else {
                return v0.compareTo(v1);
            }
        });
        return result;
    }

    private void dfs(int id, int level, Map<Integer, Integer> levels, int[][] friends) {
        if (level >= levels.getOrDefault(id, Integer.MAX_VALUE)) {
            return;
        }
        levels.put(id, level);
        for (int friend : friends[id]) {
            this.dfs(friend, level + 1, levels, friends);
        }
    }
}