class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
    set<int> s;
    int m = size(grid), n = size(grid[0]), MAX_SIZE = (min(m, n) /2) + 1;
    // single cells
    for(auto row : grid) 
        for(auto element : row) {
            s.insert(element);
            if(s.size() > 3) 
                s.erase(s.begin());
        }

    for(int Len = 1; Len < MAX_SIZE; Len++) 
        for(int row = Len; row < m - Len; row++) 
            for(int col = Len; col < n - Len; col++) {                     
                int i = row, j = col - Len, sum = 0;
                // left to top diagonal
                while(j <= col)  {
                    sum += grid[i][j];
                    i--;
                    j++;
                }
                i = row, j = col + Len;
                // right to bottom diagonal
                
                while(j >= col){
                    sum += grid[i][j];
                    i++;
                    j--;
                }
                i = row - Len + 1, j = col + 1;
                // top to right diagonal
                while(i < row)  { 
                    sum += grid[i][j];
                    i++;
                    j++;
                }
                
                i = row + Len - 1, j = col - 1;
                // bottom to left diagonal
                
                while(i > row){
                    sum += grid[i][j];
                    i--;
                    j--;
                }
                
                s.insert(sum);
                if(size(s) > 3) 
                    s.erase(s.begin());
            }
    return vector<int>(rbegin(s), rend(s));
}
};