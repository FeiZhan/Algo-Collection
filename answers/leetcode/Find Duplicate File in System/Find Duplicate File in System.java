class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> fileMap = new HashMap<>();
        for (String file : paths) {
            String[] parts = file.split(" ");
            for (int i = 1; i < parts.length; i++) {
                String[] parts1 = parts[i].split("\\(");
                if (parts1.length == 2 && parts[i].charAt(parts[i].length() - 1) == ')') {
                    String path = parts[0] + "/" + parts1[0];
                    String content = parts1[1].substring(0, parts1[1].length() - 1);
                    List<String> files = fileMap.getOrDefault(content, new LinkedList<>());
                    files.add(path);
                    fileMap.put(content, files);
                }
            }
        }
        List<List<String>> result = new LinkedList<>();
        for (List<String> duplicates : fileMap.values()) {
            if (duplicates.size() >= 2) {
                result.add(duplicates);
            }
        }
        return result;
    }
}