class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<Character, Integer> DNA_MAP = new HashMap<>();
        DNA_MAP.put('A', 0);
        DNA_MAP.put('C', 1);
        DNA_MAP.put('G', 2);
        DNA_MAP.put('T', 3);

        List<String> sequences = new LinkedList<>();
        Map<Integer, Boolean> seqMap = new HashMap<>();
        int seq = 0;
        for (int i = 0; i < s.length(); i++) {
            seq = seq * 4 + DNA_MAP.get(s.charAt(i));
            if (i >= 9) {
                if (i >= 10) {
                    seq -= DNA_MAP.get(s.charAt(i - 10)) * 1048576;
                }
                if (seqMap.containsKey(seq)) {
                    if (!seqMap.get(seq)) {
                        seqMap.put(seq, true);
                        sequences.add(s.substring(i - 9, i + 1));
                    }
                } else {
                    seqMap.put(seq, false);
                }
                //System.out.println(seq + " " + s.substring(i - 9, i + 1) + " " + seqMap.get(seq));
            }
        }
        return sequences;
    }
}