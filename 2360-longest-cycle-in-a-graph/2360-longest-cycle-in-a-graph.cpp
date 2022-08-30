class Solution {
    int maxLength = -1 ;
    void solve(vector<int>&edges, int node, vector<bool>&visited, vector<int>&store){
        if(node==-1)
            return ;
        if(visited[node]){
            int count =-1;
            for(int i=0;i<store.size();i++){
                if(store[i]==node){
                    count = i;
                    break;
                }
            }
            if(count == -1)
                return ;
            maxLength = max(maxLength, int(store.size())-count);
            return ; 
        }
        visited[node]=true;
        store.push_back(node);
        solve(edges,edges[node],visited,store);
            
    }
public:
    int longestCycle(vector<int>& edges) {
        vector<bool>visited(edges.size(),false);
        for(int i=0;i<edges.size();i++){
            if(visited[i]==false){
                vector<int>store;
                solve(edges,i,visited,store);

            }      
        }
        return maxLength;
    }
};