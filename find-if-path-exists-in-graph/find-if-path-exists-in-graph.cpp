class Solution {
    bool dfs(vector<vector<int>>&adj,vector<int>&visited,int &sources, int &destination){
        if(sources==destination)
            return true;
        if(visited[sources])
            return false;
        visited[sources]=1;
        for(auto x:adj[sources]){
            if(dfs(adj,visited,x,destination))
                return true;
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>visited(n,0);
        return dfs(adj,visited,source,destination);
    }
};