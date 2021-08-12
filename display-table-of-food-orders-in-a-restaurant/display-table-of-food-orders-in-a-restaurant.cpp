class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& s) {
        vector<vector<string>>ans;
        int n=s.size();
        if(n==0)
            return ans;
        map<int,map<string,int>>mp;
        set<string>food;
        for(int i=0;i<n;i++){
            food.insert(s[i][2]);
            mp[stoi(s[i][1])][s[i][2]]++;
        }
        vector<string>temp;
        temp.push_back("Table");
        for(auto x:food){
            temp.push_back(x);
        }
        ans.push_back(temp);
        
        
        for(auto x:mp){
            vector<string>row;
            row.push_back(to_string(x.first));
            map<string,int>mp=x.second;
            for(auto it:food){
                row.push_back(to_string(mp[it]));
            }
            ans.push_back(row);
        }
        return ans;
    }
};