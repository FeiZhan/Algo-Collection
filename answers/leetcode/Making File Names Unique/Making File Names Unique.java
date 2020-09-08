class Solution {
    public String[] getFolderNames(String[] names) {
        Map<String, Integer> nameMap = new HashMap<>();
        for (int i = 0; i < names.length; i++) {
            String name = names[i];
            int count = nameMap.getOrDefault(name, 0);
            String newName = name;
            while (nameMap.containsKey(newName)) {
                newName = name + '(' + count + ')';
                count++;
            }
            names[i] = newName;
            nameMap.put(name, count);
            nameMap.put(newName, 1);
        }
        return names;
    }
}