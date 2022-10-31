class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),j=0,i=0;
        for(int x=0;x<n;x++){
            i=x;j=0;
            while(i<n && j<m){
                if(matrix[i][j]!=matrix[x][0]){
                    return false;
                }
                i++;
                j++;
            }
        }
        for(int x=0;x<m;x++){
            i=0;j=x;
            while(i<n && j<m){
                if(matrix[i][j]!=matrix[0][x]){
                    return false;
                }
                i++;
                j++;
            }
        }
        return true;
    }
};