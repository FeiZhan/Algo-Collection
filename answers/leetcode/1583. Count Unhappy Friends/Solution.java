class Solution {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        Map<Integer, List<Integer>> preferenceMap = new HashMap<>();
        for (int i = 0; i < preferences.length; i++) {
            List<Integer> preferenceList = new LinkedList<>();
            for (int number : preferences[i]) {
                preferenceList.add(number);
            }
            preferenceMap.put(i, preferenceList);
        }

        Map<Integer, Integer> pairMap = new HashMap<>();
        for (int[] pair : pairs) {
            pairMap.put(pair[0], pair[1]);
            pairMap.put(pair[1], pair[0]);
        }

        int result = 0;
        for (int one : pairMap.keySet()) {
            boolean flag = false;
            int friend = pairMap.get(one);
            List<Integer> preference = preferenceMap.get(one);
            for (int prefer : preference) {
                if (prefer == friend) {
                    break;
                }
                int preferPair = pairMap.get(prefer);
                List<Integer> preferPreference = preferenceMap.get(prefer);
                for (int preferPrefer : preferPreference) {
                    if (preferPrefer == one) {
                        result++;
                        flag = true;
                        break;
                    } else if (preferPrefer == preferPair) {
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }

        return result;
    }
}