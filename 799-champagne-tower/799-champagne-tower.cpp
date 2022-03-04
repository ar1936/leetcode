class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>ans(102,vector<double>(102,0));
        // int ans[102][102];
        ans[0][0]=(double)poured;
        for(int r=0;r<=query_row;r++){
            for(int c=0;c<=r;c++){
                double q = (ans[r][c]-1.0)/2.0;
                if(q>0){
                    ans[r+1][c]+=q;
                    ans[r+1][c+1]+=q;
                }
            }
        }
        if(1<ans[query_row][query_glass])
            return 1.0;
        return ans[query_row][query_glass];
    }
};