class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
 
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        vector<int> ans(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]),indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int i=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans[i++]=node;
            
            for(int i=0;i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                
                if(indegree[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
        if(i==numCourses) return ans;
        return {};
    }
};