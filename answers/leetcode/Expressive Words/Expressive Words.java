class Solution {
    public int expressiveWords(String S, String[] words) {
        Map<String, List<Integer>> countMap = new HashMap<>();
        Map<String, List<String>> skeletonMap = new HashMap<>();
        for (String word : words) {
            List<Integer> counts = new LinkedList<>();
            String skeleton = this.getSkeleton(word, counts);
            countMap.put(word, counts);
            List<String> matches = skeletonMap.getOrDefault(skeleton, new LinkedList<>());
            matches.add(word);
            skeletonMap.put(skeleton, matches);
        }

        List<Integer> counts = new LinkedList<>();
        String skeleton = this.getSkeleton(S, counts);
        if (!skeletonMap.containsKey(skeleton)) {
            return 0;
        }
        List<String> matches = skeletonMap.get(skeleton);
        int extendableCount = 0;
        for (String match : matches) {
            boolean isExtendable = true;
            List<Integer> matchCounts = countMap.get(match);
            for (int i = 0; i < counts.size(); i++) {
                if (counts.get(i) < matchCounts.get(i) || (counts.get(i) > matchCounts.get(i) && counts.get(i) < 3)) {
                    isExtendable = false;
                    break;
                }
            }
            if (isExtendable) {
                extendableCount++;
            }
        }
        return extendableCount;
    }

    private String getSkeleton(String word, List<Integer> counts) {
        int count = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < word.length(); i++) {
            count++;
            if (i + 1 == word.length() || word.charAt(i) != word.charAt(i + 1)) {
                counts.add(count);
                sb.append(word.charAt(i));
                count = 0;
            }
        }
        return sb.toString();
    }
}