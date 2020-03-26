class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder, Comparator.comparing(path -> path.length()));
        Set<String> paths = new HashSet<>();
        for (String path : folder) {
            boolean flag = false;
            int index = path.indexOf("/", 0);
            while (index >= 0) {
                String subPath = path.substring(0, index);
                if (paths.contains(subPath)) {
                    flag = true;
                    break;
                }
                index = path.indexOf("/", index + 1);
            }
            if (!flag) {
                paths.add(path);
            }
        }
        return new ArrayList<>(paths);
    }
}