class Twitter {
public:

    // follower as key, followee as value
    unordered_map<int, unordered_set<int>> follower;
    
    // userId as key, vector<<time, feedId>> as value
    unordered_map<int, vector<pair<int, int>>> feed;

    int time;

    Twitter() {
        follower = {};
        feed = {};
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {    
        time++;
        feed[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        const int k = 10;

        priority_queue<pair<int, int>,
                        vector<pair<int, int>>,
                        greater<pair<int, int>>
                        > minHeap{};

        // add user's feed
        for (const auto& entry : feed[userId]) {    // vector<pair<int, int>>
            minHeap.push(entry);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        const auto& followingUserIdSet = follower[userId]; 

        for (const int followingUserId : followingUserIdSet) {    
            for (const auto& entry : feed[followingUserId]) {
                minHeap.push(entry);

                if (minHeap.size() > k) {
                    minHeap.pop();
                }

            }       
        }
        
        vector<int> result{};

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(result.begin(), result.end());

        return result;

        // 1. get all followee from  follower map
        // 2. get all the followee's vector<pair<int, int>> from the feed
        // 3. add all the followee's list<pair<int, int>> to a vector
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};
