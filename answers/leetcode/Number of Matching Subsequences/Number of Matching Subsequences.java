class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        Map<Character, List<Integer>> charMap = new HashMap<>();
        Map<Integer, Integer> indexMap = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            indexMap.put(i, 0);
            char c = words[i].charAt(0);
            List<Integer> charList = charMap.getOrDefault(c, new LinkedList<>());
            charList.add(i);
            charMap.put(c, charList);
        }
        int count = 0;
        for (char c : S.toCharArray()) {
            if (charMap.containsKey(c)) {
                List<Integer> charList = charMap.get(c);
                List<Integer> newCharList = new LinkedList<>();
                for (int index : charList) {
                    indexMap.put(index, indexMap.get(index) + 1);
                    if (indexMap.get(index) < words[index].length()) {
                        char newChar = words[index].charAt(indexMap.get(index));
                        if (newChar != c) {
                            List<Integer> temp = charMap.getOrDefault(newChar, new LinkedList<>());
                            temp.add(index);
                            charMap.put(newChar, temp);
                        } else {
                            newCharList.add(index);
                        }
                    } else {
                        count++;
                    }
                }
                charMap.put(c, newCharList);
            }
        }
        return count;
    }
}