class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        } else {
            wordList.remove(endWord);
        }
        wordList.add(endWord);
        if (wordList.contains(beginWord)) {
            wordList.remove(beginWord);
        }
        wordList.add(0, beginWord);
        int length = beginWord.length();
        Map<Integer, List<Integer>> ladderMap = new HashMap<>();
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                int count = 0;
                for (int k = 0; k < length; k++) {
                    if (wordList.get(i).charAt(k) != wordList.get(j).charAt(k)) {
                        count++;
                    }
                    if (count > 1) {
                        break;
                    }
                }
                if (count == 1) {
                    List<Integer> ladderList = ladderMap.getOrDefault(i, new LinkedList<>());
                    ladderList.add(j);
                    ladderMap.put(i, ladderList);
                    ladderList = ladderMap.getOrDefault(j, new LinkedList<>());
                    ladderList.add(i);
                    ladderMap.put(j, ladderList);
                }
            }
        }
        Map<Integer, Integer> distances = new HashMap<>();
        distances.put(0, 1);
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(0);
        while (!queue.isEmpty()) {
            int current = queue.poll();
            if (distances.containsKey(current) && ladderMap.containsKey(current)) {
                int distance = distances.get(current) + 1;
                List<Integer> ladderList = ladderMap.get(current);
                for (int neighbor : ladderList) {
                    if (!distances.containsKey(neighbor) || distances.get(neighbor) > distance) {
                        //System.out.println(neighbor + " " + wordList.get(neighbor) + " " + distance);
                        if (neighbor == wordList.size() - 1) {
                            return distance;
                        }
                        distances.put(neighbor, distance);
                        queue.add(neighbor);
                    }
                }
            }
        }
        return distances.getOrDefault(wordList.size() - 1, 0);
    }
}