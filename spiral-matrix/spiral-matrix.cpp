class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int up=0,right=col-1,left=0,down=row-1;
        vector<int>ans;
        while(ans.size()<row*col){
            for(int col=left;col<=right;col++){
                ans.push_back(matrix[up][col]);
            }
            for(int row=up+1;row<=down;row++){
                ans.push_back(matrix[row][right]);
            }
            if(up!=down){
                for(int col=right-1;col>=left;col--){
                    ans.push_back(matrix[down][col]);
                }
            }
            if(left!=right){
                for(int row=down-1;row>up;row--){
                    ans.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            up++;
            down--;
        }
        return ans;
    }
};