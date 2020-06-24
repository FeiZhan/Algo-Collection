class UndergroundSystem {

    private Map<Integer, String> stations = new HashMap<>();
    private Map<Integer, Integer> times = new HashMap<>();

    private Map<String, Integer> counts = new HashMap<>();
    private Map<String, Integer> totalTimes = new HashMap<>();

    public UndergroundSystem() {
    }

    public void checkIn(int id, String stationName, int t) {
        this.stations.put(id, stationName);
        this.times.put(id, t);
    }

    public void checkOut(int id, String stationName, int t) {
        String names = this.stations.get(id) + '.' + stationName;
        int timeDiff = t - this.times.get(id);
        this.counts.put(names, this.counts.getOrDefault(names, 0) + 1);
        this.totalTimes.put(names, this.totalTimes.getOrDefault(names, 0) + timeDiff);
    }

    public double getAverageTime(String startStation, String endStation) {
        String names = startStation + '.' + endStation;
        int count = this.counts.get(names);
        int time = this.totalTimes.get(names);
        return (double) time / count;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */