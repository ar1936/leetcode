class Solution {
public:
        vector<int> row_offset = {0,  0, 1, -1}; //right, left, down, up
    vector<int> col_offset = {1, -1, 0,  0};
   
    void BFS(vector<vector<int>>& maze, vector<int> start, vector<vector<int>>& distance){
        queue<vector<int>> Q;
        Q.push({start[0], start[1]});
        while(!Q.empty()){
            auto S = Q.front();
            Q.pop();
            for(int offset = 0; offset < 4; offset++){
                int new_row = S[0] + row_offset[offset];
                int new_col = S[1] + col_offset[offset];
                int count = 0;
                while (new_row >=0 && new_row < maze.size() && new_col >= 0 && new_col < maze[0].size() && maze[new_row][new_col] == 0){
                    new_row += row_offset[offset];
                    new_col += col_offset[offset];
                    count += 1;
                }
                if(distance[S[0]][S[1]] + count < distance[new_row - row_offset[offset]][new_col - col_offset[offset]]){
                    distance[new_row - row_offset[offset]][new_col - col_offset[offset]] = distance[S[0]][S[1]] + count;
                    Q.push({new_row - row_offset[offset], new_col - col_offset[offset]});
                }
            }
        }
    }
    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> distance(maze.size(), vector<int>(maze[0].size(), INT_MAX));
        distance[start[0]][start[1]] = 0;
        BFS(maze, start, distance);
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};