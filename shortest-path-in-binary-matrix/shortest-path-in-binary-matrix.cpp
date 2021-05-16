int dx[] = {-1, 1, -1, 1, 0, 0, 1, -1};
int dy[] = {-1, 1, 1, -1, 1, -1, 0, 0};
class Solution
{
    public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int N = grid.size();
        int M = grid[0].size();
        if(N==0||M==0)
            return -1;
        int ans=1;
        if (grid[0][0] != 0 || grid[N - 1][M - 1] != 0)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            if(x==N-1 && y==M-1)
                return grid[x][y];
            for (int k = 0; k < 8; k++)
            {
                int new_x = x + dx[k];
                int new_y = y + dy[k];
                if ((new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && grid[new_x][new_y] == 0))
                {
                    grid[new_x][new_y] = grid[x][y] + 1;
                    q.push({new_x,new_y});
                }
            }
            q.pop();
        }
       
        return -1;
    }
};