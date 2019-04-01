class Solution {
    public String reorganizeString(String S) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : S.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        PriorityQueue<Character> queue = new PriorityQueue<>((c1, c2) -> counts.get(c1) - counts.get(c2));
        queue.addAll(counts.keySet());
        int index = 0;
        StringBuilder sb = new StringBuilder();
        while (!queue.isEmpty()) {
            char c = queue.poll();
            int count = counts.get(c);
            if (count * 2 > S.length() + 1) {
                return "";
            }
            if (sb.length() * 2 + 1 < S.length()) {
                sb.append(c);
            } else {
                //System.out.println(c + " " + count + ": " + index + " " + sb.toString());
                if (index > sb.length()) {
                    return "";
                }
                sb.insert(index, c);
                index += 2;
            }
            if (count == 1) {
                counts.remove(c);
            } else {
                counts.put(c, count - 1);
                queue.add(c);
            }
        }
        return sb.toString();
    }
}