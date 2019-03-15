class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        Map<Character, Integer> charMap = new HashMap<>();
        for (String str : B) {
            Map<Character, Integer> counts = new HashMap<>();
            for (char c : str.toCharArray()) {
                counts.put(c, counts.getOrDefault(c, 0) + 1);
            }
            for (char key : counts.keySet()) {
                int count = Math.max(counts.get(key), charMap.getOrDefault(key, 0));
                charMap.put(key, count);
                //System.out.println(key + ": " + count);
            }
        }
        List<String> results = new LinkedList<>();
        for (String str : A) {
            Map<Character, Integer> counts = new HashMap<>();
            for (char c : str.toCharArray()) {
                counts.put(c, counts.getOrDefault(c, 0) + 1);
            }
            boolean flag = true;
            for (char key : charMap.keySet()) {
                if (!counts.containsKey(key) || counts.get(key) < charMap.get(key)) {
                    //System.out.println(key + " not in " + str);
                    flag = false;
                    break;
                }
            }
            if (flag) {
                results.add(str);
            }
        }
        return results;
    }
}