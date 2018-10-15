class Solution {
    public int minMutation(String start, String end, String[] bank) {
        Map<String, Integer> geneMap = new HashMap<>();
        Map<Integer, String> indexMap = new HashMap<>();
        geneMap.put(start, 0);
        indexMap.put(0, start);
        geneMap.put(end, 1);
        indexMap.put(1, end);

        boolean flag = false;
        for (int i = 0; i < bank.length; i++) {
            String gene = bank[i];
            if (!geneMap.containsKey(gene)) {
                geneMap.put(gene, i + 2);
                indexMap.put(i + 2, gene);
            } else if (gene.equals(end)) {
                flag = true;
            }
        }
        if (!flag) {
            return -1;
        }

        Map<Integer, Set<Integer>> mutationMap = new HashMap<>();
        for (String g0 : geneMap.keySet()) {
            for (String g1 : geneMap.keySet()) {
                int count = 0;
                for (int i = 0; i < g0.length(); i++) {
                    if (g0.charAt(i) != g1.charAt(i)) {
                        count++;
                    }
                    if (count >= 2) {
                        break;
                    }
                }
                if (count == 1) {
                    int index0 = geneMap.get(g0);
                    int index1 = geneMap.get(g1);
                    Set<Integer> mutationSet = mutationMap.getOrDefault(index0, new HashSet<>());
                    mutationSet.add(index1);
                    mutationMap.put(index0, mutationSet);
                    mutationSet = mutationMap.getOrDefault(index1, new HashSet<>());
                    mutationSet.add(index0);
                    mutationMap.put(index1, mutationSet);
                }
            }
        }

        flag = false;
        int count = 0;
        Queue<Integer> queue1 = new LinkedList<>();
        queue1.add(0);
        while (!queue1.isEmpty()) {
            Queue<Integer> queue0 = new LinkedList<>(queue1);
            queue1.clear();
            while (!queue0.isEmpty()) {
                int current = queue0.poll();
                if (current == 1) {
                    flag = true;
                    break;
                }
                if (mutationMap.containsKey(current)) {
                    for (int mutation : mutationMap.get(current)) {
                        if (mutationMap.containsKey(mutation)) {
                            queue1.add(mutation);
                            mutationMap.get(mutation).remove(current);
                        }
                    }
                    mutationMap.remove(current);
                }
            }
            if (flag) {
                break;
            }
            count++;
        }
        return flag ? count : -1;
    }
}