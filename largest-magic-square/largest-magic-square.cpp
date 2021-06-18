class Solution {
    int solve(vector<vector<int>>&grid,int x,int y, int size){
        int n=grid.size(),m=grid[0].size();
        
    
        if((x+size)>n||(y+size)>m)
        {
            return 1;
        }
        
        // very important part of this question sum1 contains sum of diagonal 1 and sum2 contains sum of diagonal 2 
        long long sum1=0,sum2=0;
        for(int k=0;k<size;k++){
            sum1+=grid[x+k][y+k];
            sum2+=grid[size+x-k-1][y+k];
        }
        
        // if sum of both diagonal is not equal then we simply return square size 1 
        if(sum1!=sum2)
            return 1;
        
        
        // check for row and col sum 
        for(int i=0;i<size;i++){
            long long row_sum=0,col_sum=0;
            for(int j=0;j<size;j++){
                row_sum+=grid[x+i][y+j];
                col_sum+=grid[x+j][y+i];
            }
            
            
            if(row_sum!=sum1||col_sum!=sum1)
                return 1;
        }
        
        
        return size;
        
    }
   

public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans=1,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                // k represent size of each square at each index;
                
                
                for(int k=0;k<=min(n,m);k++){
                    ans=max(ans,solve(grid,i,j,k)); // -> i, j represent a index of grid and k represent size of square; 
                }
            }
        }
        return ans;
    }
};

