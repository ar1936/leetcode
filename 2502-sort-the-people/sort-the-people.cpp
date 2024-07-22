class Solution {
public:
    vector<string> sortPeople(vector<string>& a, vector<int>& b) {
        vector<string>ans;
        vector<pair<int,string>>v;
        for(int i=0;i<a.size();i++){
            v.push_back({b[i],a[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        for(auto x:v){
            ans.push_back(x.second);
        }
        return ans;
    }
};