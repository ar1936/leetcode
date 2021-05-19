class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<pair<int,int>> dirs ({{0,1},{1,0},{-1,0},{0,-1}});
        return StopsAtDes(maze,start[0],start[1],destination,dirs);
    }
private:
    bool StopsAtDes(vector<vector<int>>& maze, int r, int c, vector<int>& des, vector<pair<int,int>> &dirs)
    {
        if(r < 0 || c < 0 || r == maze.size () || c == maze[r].size())
            return false;
			
        if(r == des[0] && c == des[1])
            return true;
        
		//STEP 1 mark visisted
        maze[r][c] = -1;
		
		//STEP 2 try all possible directions
        for(auto d : dirs)
        {
			// generate new positions
            int nr = r, fr = r + d.first;
            int nc = c, fc = c + d.second;
            
            while(fr >= 0 && fc >= 0 && fr < maze.size() && fc < maze[0].size() && maze[fr][fc] != 1)
                nr = fr, nc = fc, fr += d.first, fc += d.second;
			
			// if the new position wasnt seen && stops at the destination return true
            if(maze[nr][nc] != -1 && StopsAtDes(maze,nr,nc,des,dirs))
                return true;
        }
        return false;
    }
};