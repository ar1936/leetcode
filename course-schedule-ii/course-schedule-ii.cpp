class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
 
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        vector<int> ans(numCourses);
        
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]),indegree[p[0]]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int i=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            ans[i++]=node;
            
            for(auto nbr:graph[node]){
                indegree[nbr]--;
                
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        if(i==numCourses) return ans;
        return {};
    }
};