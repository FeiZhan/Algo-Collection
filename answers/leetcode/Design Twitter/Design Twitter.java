import java.util.SortedSet;

class Twitter {

    class User {
        public int id = 0;
        public Set<Integer> followees = new HashSet<>();
        public List<Tweet> tweets = new LinkedList<>();
    }

    class Tweet {
        public int id = 0;
        public int order = 0;
    }

    private int order;
    private Map<Integer, User> userMap;

    /** Initialize your data structure here. */
    public Twitter() {
        this.order = 0;
        this.userMap = new HashMap<>();
    }

    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        Tweet tweet = new Tweet();
        tweet.id = tweetId;
        tweet.order = this.order;
        this.order++;
        User user = this.getOrCreateUser(userId);
        user.tweets.add(tweet);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> feed = new LinkedList<>();
        if (this.userMap.containsKey(userId)) {
            SortedSet<Tweet> tweets = new TreeSet<Tweet>((Tweet t0, Tweet t1) -> t1.order - t0.order);
            User user = this.userMap.get(userId);
            tweets.addAll(user.tweets);
            for (int followee : user.followees) {
                if (this.userMap.containsKey(followee)) {
                    User followeeUser = this.userMap.get(followee);
                    tweets.addAll(followeeUser.tweets);
                }
            }
            while (tweets.size() > 10) {
                tweets.remove(tweets.last());
            }
            for (Tweet tweet : tweets) {
                feed.add(tweet.id);
            }
        }
        return feed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
        User user = this.getOrCreateUser(followerId);
        user.followees.add(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        User user = this.getOrCreateUser(followerId);
        user.followees.remove(followeeId);
    }

    private User getOrCreateUser(int userId) {
        if (!this.userMap.containsKey(userId)) {
            User user = new User();
            user.id = userId;
            this.userMap.put(userId, user);
        }
        return this.userMap.get(userId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */