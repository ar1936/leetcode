// int dx={1,-1,0,0,-1,1,-1,1};
// int dy={0,0,-1,1,-1,1,1,-1};
class Solution {
public:
    void solve(vector<vector<int>>&image,int x,int y,int newColour,int N,int M,int oldColour){
        if(x<0||x>=N||y<0||y>=M||image[x][y]!=oldColour||image[x][y]==newColour)
            return ;
        image[x][y]=newColour;
        solve(image,x+1,y,newColour,N,M,oldColour);
        solve(image,x-1,y,newColour,N,M,oldColour);
        solve(image,x,y+1,newColour,N,M,oldColour);
        solve(image,x,y-1,newColour,N,M,oldColour);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int N=image.size();
        int M=image[0].size();
        int oldColor=image[sr][sc];
        solve(image,sr,sc,newColor,N,M,oldColor);
        return image;
        
    }
};