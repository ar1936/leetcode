// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int count=0;
//         queue<int>q;
//         vector<int>indegree(numCourses,0);
//         vector<int>adj[numCourses+1];
//         for(int i=0;i<prerequisites.size();i++){
//             adj[prerequisites[i][i]].push_back(prerequisites[i][0]);
//         }
//         for(int i=0;i<prerequisites.size();i++){
//             indegree[prerequisites[i][0]]++;
//         }
        
//         for(int i=0;i<numCourses ;i++)
//         {
//             if(indegree[i]==0)
//                 q.push(i); 
//         }
        
//         while(!q.empty()){
//             int node=q.front();
//             for(auto x:adj[node]){
//                 indegree[x]--;
//                 if(indegree[x]==0)
//                     q.push(x);
               
//             }
//             count++;
//             q.pop();
//         }
//         cout<<count<<" ";
//         return (numCourses==count+1)?true:false;
//     }
// };


class Solution {
public:
    bool canFinish(int numCourses , vector<vector<int>>& a) {
        //Topological Sort Concept
        // BFS
        int n=a.size();int ct=0;
        int in[numCourses ];//indegree of vertices
        
        for(int i=0;i<numCourses ;i++)in[i]=0;
        
        vector<int> adj[numCourses +1];
        queue<int> q;
        
        for(int i=0;i<a.size();i++) adj[a[i][1]].push_back(a[i][0]);//storing directed graph
        
        for(int i=0;i<n;i++)
        {
            in[a[i][0]]++;// calculating indegree
        }
        
        for(int i=0;i<numCourses ;i++)
        {
            if(in[i]==0) q.push(i); //if indegree==0, push in queue
        }
        
        while(q.empty()==false)
        {
            int z=q.front();
            
            for(auto x: adj[z])
            {
                in[x]--;
                if(in[x]==0) q.push(x);
            }
           ct++; q.pop();
        }
        
        if(ct==numCourses )return true;
        else return false;
    }
};