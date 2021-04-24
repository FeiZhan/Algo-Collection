class AuthenticationManager {

    private int timeToLive;
    private Map<String, Integer> tokenIds;

    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
        this.tokenIds = new HashMap<>();
    }

    public void generate(String tokenId, int currentTime) {
        this.tokenIds.put(tokenId, currentTime + this.timeToLive);
    }

    public void renew(String tokenId, int currentTime) {
        int expiryTime = this.tokenIds.getOrDefault(tokenId, -1);
        if (expiryTime > currentTime) {
            this.tokenIds.put(tokenId, currentTime + this.timeToLive);
        }
    }

    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (String tokenId : this.tokenIds.keySet()) {
            int expiryTime = this.tokenIds.get(tokenId);
            if (expiryTime > currentTime) {
                count++;
            }
        }

        return count;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */