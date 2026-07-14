class Twitter {
public:

    map<int,unordered_set<int>> following;
    vector<pair<int,int>> q;
    Twitter() {
       
    }
    
    void postTweet(int userId, int tweetId) {
        q.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int n=q.size();
        vector<int> ans;
        for(int i=(n-1);i>=0;i--){

            auto it=following[userId].find(q[i].first);
            if(q[i].first==userId || it!=following[userId].end()){
                ans.push_back(q[i].second);
                if(ans.size()==10){
                    break;
                }
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */