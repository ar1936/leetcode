class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    v.push_back({i,j});
                }
            }
        }
        int k=0;
        while(k<v.size()){
            for(int i=0;i<matrix.size();i++){
                for(int j=0;j<matrix[i].size();j++){
                    if(j==v[k].second)
                        matrix[i][j]=0;
                    if(i==v[k].first)
                        matrix[i][j]=0;
                    
                }
            }
            k++;
        }
    }
};