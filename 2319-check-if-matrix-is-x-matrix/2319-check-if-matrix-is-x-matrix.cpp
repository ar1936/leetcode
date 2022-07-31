class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),i=0,j=0,count_zero=0;
        while(i<n && j<n){
            if(grid[i][j]==0)
                return false;
            i++;j++;
            
        }
        i=n-1, j=0;
        while(i>=0 && j<n){
            if(grid[i][j]==0)
                return false;
            i--;
            j++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    count_zero++;
            }
        }
        if(n%2==0)
            return count_zero==(n*n-2*n);
        return count_zero==(n*n-2*n+1);
    }
};
