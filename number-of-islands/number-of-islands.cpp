//                         //BFS

// //     int N,M;
// //     int dx[]={1,0,-1,0};
// //     int dy[]={0,1,0,-1};
// // class Solution {
// // public:
  
// //     bool isValid(int x,int y){
// //         return (0<=x)&&(x<N)&&(0<=y)&&(y<M);
// //     }
// //     int numIslands(vector<vector<char>>& mat) {
// //         N= mat.size(); M=mat[0].size();
// //         int ans=0;
// //         vector<vector<bool>>visited(301,vector<bool>(301));
// //         //loop start from here  
// //         for(int i=0;i<N;i++){
// //             for(int j=0;j<M;j++){
// //                 if(!visited[i][j]&&mat[i][j]=='1'){
// //                     ans++;
// //                     queue<pair<int,int>>q;
// //                     q.push({i,j});
// //                     visited[i][j]=true;
// //                     while(!q.empty()){
// //                         int x=q.front().first;
// //                         int y=q.front().second;
// //                         q.pop();
// //                         for(int k=0;k<4;k++){
// //                             int new_x=x+dx[k];
// //                             int new_y=y+dy[k];
// //                             if(isValid(new_x,new_y)&&!visited[new_x][new_y]&&mat[new_x][new_y]=='1'){
// //                                 q.push({new_x,new_y});
// //                                 visited[new_x][new_y]=true;
// //                             }
// //                         }
// //                     }
// //                 }
// //             }
   
// //         }
// //         return ans;
// //     }
// // };

//                     //DFS

// void mark_visited(vector<vector<char>>&mat,int x,int y, int N,int M){
//     if(x<0||x==N||y<0||y==M||mat[x][y]=='0')
//         return ;
    
//     mat[x][y]='0';
//     mark_visited(mat,x+1,y,N,M);
//     mark_visited(mat,x,y+1,N,M);
//     mark_visited(mat,x-1,y,N,M);
//     mark_visited(mat,x,y-1,N,M);

   

// }
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& mat) {
//         int N=mat.size();
//         int M=mat[0].size();
//         if(N==0)
//             return 0;
//         int ans=0;
//         for(int i=0;i<N;i++){
//             for(int j=0;j<M;j++){
//                 if(mat[i][j]=='1'){
//                     ans++;
//                     mark_visited(mat,i,j,N,M);
//                 }
//             }
//         }
//         return ans;
//     }
// };



class Solution {
public:
    bool isValid(int x,int y,int m,int n,vector<vector<char>>& a){
        if(x<0||x>m-1||y<0||y>n-1||a[x][y]!='1')return false;
        return true;
    }
    
    int numIslands(vector<vector<char>>& a) {
        int count=0,i,j,k;
        int m,n;
        m=a.size();
        n=a[0].size();
        int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(a[i][j]=='1'){
                    ++count;
                    a[i][j]='2';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                        while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        for(k=0;k<4;++k){
                            int x,y;
                            x=p.first+dx[k];
                            y=p.second+dy[k];
                            if(isValid(x,y,m,n,a)){
                                a[x][y]='0';
                                q.push({x,y});
                            }
                        }
                    }
                }
                
            }
        }
        
        return count;
        
    }
};