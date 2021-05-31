class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        string ans="";
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        while(!pq.empty()){
            int count=pq.top().first;
            char c=pq.top().second;
            pq.pop();
            for(int i=0;i<count;i++){
                ans.push_back(c);
            }
        }
        return ans;
    }
};