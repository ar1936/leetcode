
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        priority_queue<pair<int,string>>pq;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto x:mp){
            pq.push({-1*x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.insert(ans.begin(),pq.top().second);
            pq.pop();
        }
           
        return ans;
    }
};