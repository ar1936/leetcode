int parents[205];
class Solution {
    void make_set(int n){
        for(int i=0;i<n;i++){
            parents[i]=i;
        }
    }
    int find_set(int x){
        if(x==parents[x])
            return x;
        return parents[x]=find_set(parents[x]);
    }
    void find_union(int u,int v){
        int a=find_set(u);
        int b=find_set(v);
        if(a!=b)
        {
            parents[a]=b;
        }
        
    }
    
public:
    int findCircleNum(vector<vector<int>>& grids) {
        int n=grids.size(),ans=0,i,j;
        make_set(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(grids[i][j]==1)
                    find_union(i,j);
            }
        }
        for(int i=0;i<n;i++){
            if(parents[i]==i)
                ans++;
        }
        return ans;
    }
};