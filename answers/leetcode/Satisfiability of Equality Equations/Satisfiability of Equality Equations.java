class Solution {
    public boolean equationsPossible(String[] equations) {
        Map<Character, Character> roots = new HashMap<>();
        Map<Character, Set<Character>> sets = new HashMap<>();
        Map<Character, Set<Character>> unequal = new HashMap<>();
        for (String equation : equations) {
            char c0 = equation.charAt(0);
            char c1 = equation.charAt(3);
            if (c0 > c1) {
                char temp = c0;
                c0 = c1;
                c1 = temp;
            }
            if (!roots.containsKey(c0)) {
                roots.put(c0, c0);
                Set<Character> tempSet = new HashSet<>();
                tempSet.add(c0);
                sets.put(c0, tempSet);
                unequal.put(c0, new HashSet<>());
            }
            char root0 = roots.get(c0);
            Set<Character> set0 = sets.get(root0);
            Set<Character> unequal0 = unequal.get(root0);
            if (!roots.containsKey(c1)) {
                roots.put(c1, c1);
                Set<Character> tempSet = new HashSet<>();
                tempSet.add(c1);
                sets.put(c1, tempSet);
                unequal.put(c1, new HashSet<>());
            }
            char root1 = roots.get(c1);
            Set<Character> set1 = sets.get(root1);
            Set<Character> unequal1 = unequal.get(root1);
            if (equation.charAt(1) == '=' && root0 != root1) {
                Set<Character> tempSet = new HashSet<>(unequal0);
                tempSet.retainAll(set1);
                if (tempSet.size() > 0) {
                    return false;
                } else {
                    for (char c : set1) {
                        roots.put(c, root0);
                    }
                    set0.addAll(set1);
                    sets.remove(c1);
                    unequal0.addAll(unequal1);
                    unequal.remove(c1);
                }
            } else if (equation.charAt(1) == '!') {
                if (set0.contains(c1)) {
                    return false;
                } else {
                    unequal0.add(root1);
                    unequal1.add(root0);
                }
            }
        }
        return true;
    }
}

