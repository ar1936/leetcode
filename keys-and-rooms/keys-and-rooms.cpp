class Solution {
public:
    void solve(vector<vector<int>>&rooms,vector<bool>&visited,int node){
        visited[node]=true;
        for(auto x:rooms[node]){
            if(!visited[x])
                solve(rooms,visited,x);
            
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        solve(rooms,visited,0);
        for(int i=0;i<n;i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};