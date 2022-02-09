// my try

// int dx[4]={1,-1,0,0};
// int dy[4]={0,0,1,-1};
// class Solution {
//     void dfs(vector<vector<int>>&land, int x, int y,int &x1, int &y1){
//         int row=land.size(),col=land[0].size();
//         if(x<0||x>=row||y<0||y>=col||land[x][y]==0)
//             return;
//         x1=max(x1,x);
//         y1=max(y1,y);
//         land[x][y]=0;
//         for(int i=0;i<4;i++){
//             dfs(land,x+dx[i],y+dy[i],x1,y1);
//         }
//     }
// public:
//     vector<vector<int>> findFarmland(vector<vector<int>>& land) {
//         vector<vector<int>>ans;
//         int row=land.size(),col=land[0].size();
//         for(int i=0;i<row;i++){
//             vector<int>temp;
//             for(int j=0;j<col;j++){
//                 if(land[i][j]==1)
//                 {
//                     int x1=i,y1=j;
//                     temp.push_back(i);
//                     temp.push_back(j);
//                     dfs(land,i,j,x1,y1);
//                     temp.push_back(x1);
//                     temp.push_back(y1);
//                 }
//             }
//             ans.push_back(temp);
//         }
//         if(ans.size()==1 &&ans.back().size()==0)
//             return {};
//         vector<vector<int>>ans1;
//         for(auto x:ans){
//             if(x.size()>4){
//                 int m=x.size()/4;
//                 ans1.resize(m);
//                 for(int i=0;i<m;i++){
//                     ans1[i].push_back(x[4*i+0]);
//                     ans1[i].push_back(x[4*i+1]);
//                     ans1[i].push_back(x[4*i+2]);
//                     ans1[i].push_back(x[4*i+3]);
//                 }
//             }
//             else if(x.size()!=0)
//                 ans1.push_back(x);
//         }
//         return ans1;
//     }
// };



class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        for(int i = 0 ; i < land.size() ; ++i)
            for(int j = 0 ; j < land[0].size() ; ++j)
                if(land[i][j] == 1)
                    dfs(i , j , land);
        return res;
    }
    void dfs(int x , int y , vector<vector<int>> &land)
    {
        // -1 : means visited
        if(x < 0 or y < 0 or x == land.size() or y == land[0].size() or land[x][y] == -1 or land[x][y] == 0)
            return;
        
        ok(x , y , land);
        
        land[x][y] = -1; // marking visited
        dfs(x - 1 , y , land); // UP
        dfs(x + 1 , y , land); // DOWN
        dfs(x , y - 1 , land); // LEFT
        dfs(x , y + 1 , land); // RIGHT
    }
    
    void ok(int x , int y , vector<vector<int>> &land)
    {
        bool up   = (x - 1 < 0 or land[x - 1][y] == 0);
        bool left = (y - 1 < 0 or land[x][y - 1] == 0);
        
        bool right = (y + 1 >= land[0].size() or land[x][y + 1] == 0);
        bool down  = (x + 1 >= land.size() or land[x + 1][y] == 0);
        
        if(up and left)
            res.push_back({x , y});
        if(right and down)
            res.back().push_back(x) , res.back().push_back(y);
    }
};