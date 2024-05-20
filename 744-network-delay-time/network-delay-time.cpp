class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>mp;
        for(auto t:times){
            mp[t[0]].push_back({t[1],t[2]});
            // mp[t[1]].push_back({t[0],t[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
        while(pq.size()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto v:mp[node]){
                if(d+v.second<dist[v.first]){
                    pq.push({d+v.second,v.first});
                    dist[v.first] = d+v.second;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n;i++){
            ans = max(ans,dist[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};