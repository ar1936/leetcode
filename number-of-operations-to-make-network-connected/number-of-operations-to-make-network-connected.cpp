// int parents[10006];
// class Solution {
//     void make_set(int n){
//         for(int i=0;i<=n;i++){
//             parents[i]=i;
//         }
//     } 
//     int find_set(int x){
//         if(x==parents[x])
//             return x;
//         return parents[x]=find_set(parents[x]);
//     }
//     void union_set(int u, int v){
//         int a=find_set(u);
//         int b=find_set(v);
//         if(a!=b)
//             parents[b]=a;
//     }
// public:
    
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int size=connections.size(),ans=0;
//         make_set(n);
//         for(int i=0;i<size;i++){
//             union_set(connections[i][0],connections[i][1]);
//         }
//         for(int i=0;i<=n;i++){
//             if(parents[i]==0)
//                 ans++;
//             cout<<parents[i]<<" ";
//         }
//         cout<<"\n";
//         return ;
//     }
// };

class Solution {
public:
    
    int find(vector<int> &parent, int v){
        int root = v;
        while(root != parent[root]){
            root = parent[root];
        }
        
        return root;
    }
    
    void unify(vector<int> &parent, int u, int v){
        int root_u = find(parent, u);
        int root_v = find(parent, v);
        
        if(root_u == root_v){
            return;
        }
        parent[root_u] = root_v;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int i, j, used = 0, redundent = 0, total = 0;
        vector<int> parent(n);
        for(i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(i = 0; i < connections.size(); i++){
            if(find(parent, connections[i][0]) == find(parent, connections[i][1])){
                redundent++;
            }else{
                used++;
                unify(parent, connections[i][0], connections[i][1]);
            }
        }
        
        for(i = 0; i < n; i++){
            total += parent[i] == i? 1 : 0;
        }
        
        // cout << used << " " << redundent << " " << total << endl;
        return total - 1 <= redundent ? total-1 : -1;
    }
};