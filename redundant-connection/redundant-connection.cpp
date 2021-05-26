// int parents[1001];
// class Solution {
// public:
//     void make_set(int n){
//         for(int i=1;i<=n;i++){
//             parents[i]=i;
//         }
//     }
//     int find_set(int x){
//         if(x==parents[x])
//             return x;
//         return parents[x]=find_set(parents[x]);
//     }
//     void set_union(int u, int v){
//         int a=find_set(u);
//         int b=find_set(v);
//         if(a!=b)
//             parents[a]=b; 
//     }
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         int n=edges.size(),mx=INT_MIN,ans=0;
//         make_set(n);
//         for(int i=0;i<n;i++){
//             set_union(edges[i][0],edges[i][1]);
//         }
//         for(int i=1;i<n;i++){
//             if(parents[edges[i][0]]==parents[edges[i][1]])
//                 return {edges[i][0],edges[i][1]};
//         }
//         return {};
//     }
// };

class Solution {
public:

int find(int x, vector<int> &parent)
{
        return parent[x] == x ? x : find(parent[x] , parent);
}
        
vector<int> findRedundantConnection(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> res;
        
        vector<int> parent(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        
        for(int i=0; i<n; i++)
        {
            int f = find(A[i][0] , parent);
            int s = find(A[i][1] , parent);
            if(f == s)
            {
                res.clear();
                res.push_back(A[i][0]);
                res.push_back(A[i][1]);
            }
            else
            {
                parent[f] = s;
            }
        }
        
        return res;
    }
};