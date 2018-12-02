class Twitter {
private:
    struct User {
        unordered_set<int> followers;
        unordered_set<int> followees;
        deque<pair<int, int>> tweets;
        vector<int> newsFeed;
        bool newsFeedValid = true;
    };

    const int maxTweetCount = 10;

    int nextTimestamp = 1;
    unordered_map<int, User*> users;

    User* getUser(int userId) {
        const auto it = users.find(userId);
        if (it != users.end()) {
            return it->second;
        }
        else {
            const auto user = new User{};
            user->followers.insert(userId);
            user->followees.insert(userId);
            users.insert({userId, user});
            return user;
        }
    }

public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        const auto user = getUser(userId);
        const auto timestamp = nextTimestamp;
        nextTimestamp++;
        if (user->tweets.size() == maxTweetCount) {
            user->tweets.pop_back();
        }
        user->tweets.push_front({timestamp, tweetId});
        for (const auto followerId : user->followers) {
            const auto follower = getUser(followerId);
            if (follower->newsFeedValid) {
                if (follower->newsFeed.size() == maxTweetCount) {
                    follower->newsFeed.pop_back();
                }
                follower->newsFeed.insert(follower->newsFeed.begin(), tweetId);
            }
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        const auto user = getUser(userId);
        if (!user->newsFeedValid) {
            user->newsFeed.clear();
            const auto cmp = [&](const tuple<int, int, User*>& a, const tuple<int, int, User*>& b) {
                return get<0>(a) < get<0>(b);
            };
            priority_queue<tuple<int, int, User*>, vector<tuple<int, int, User*>>, decltype(cmp)> q(cmp);
            for (const auto followeeId : user->followees) {
                const auto followee = getUser(followeeId);
                if (followee->tweets.size() > 0) {
                    q.push({followee->tweets[0].first, 0, followee});
                }
            }
            for (int i = 0; (i < maxTweetCount) && !q.empty(); i++) {
                const auto t = q.top();
                q.pop();
                const auto followee = get<2>(t);
                const auto index = get<1>(t);
                user->newsFeed.push_back(followee->tweets[index].second);
                if (index + 1 < followee->tweets.size()) {
                    q.push({followee->tweets[index + 1].first, index + 1, followee});
                }
            }
            user->newsFeedValid = true;
        }
        return user->newsFeed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        const auto follower = getUser(followerId);
        follower->followees.insert(followeeId);
        follower->newsFeedValid = false;
        getUser(followeeId)->followers.insert(followerId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        const auto follower = getUser(followerId);
        follower->followees.erase(followeeId);
        follower->newsFeedValid = false;
        getUser(followeeId)->followers.erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
