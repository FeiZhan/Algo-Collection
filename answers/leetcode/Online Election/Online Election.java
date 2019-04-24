class TopVotedCandidate {

    TreeMap<Integer, Integer> tops = new TreeMap<>();

    public TopVotedCandidate(int[] persons, int[] times) {
        int count = 0;
        int top = 0;
        Map<Integer, Integer> votes = new HashMap<>();
        for (int i = 0; i < persons.length; i++) {
            votes.put(persons[i], votes.getOrDefault(persons[i], 0) + 1);
            if (votes.get(persons[i]) >= count) {
                count = votes.get(persons[i]);
                top = persons[i];
                this.tops.put(times[i], top);
            }
        }
    }
    
    public int q(int t) {
        int key = this.tops.floorKey(t);
        return this.tops.get(key);
    }
}

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */