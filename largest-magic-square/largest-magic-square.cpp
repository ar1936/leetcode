#define ll long long
class Solution {
public:

	// checking each square starting at vertex (x,y) with size s
    int check(vector<vector<int>>& grid,int x,int y,int s){
	
		// checking boundary conditions for size of square , 
		// else returning 1 , which is the minimum size possible
        if(x+s>grid.size() || y+s>grid[0].size()) return 1;
		
        ll sum = 0;
		// taking sum of first diagonal in sum variable 
        for(int k=0; k<s ;k++){
            sum+=grid[k+x][y+k];
        }
        ll sum2=0;
		// taking sum of first diagonal in sum2 variable 
        for(int k=0; k<s ;k++){
            sum2+=grid[x+s-1-k][y+k];
        }
		
		// if both sums are different , return 1 
        if(sum2!=sum) return 1;
        
		// checking sum for all rows and columns
        for(int i=0 ;i<s ;i++){
            ll sumrow=0;
            for(int j=0 ;j<s ;j++) sumrow+=grid[i+x][y+j];
            ll sumcol=0;
            for(int j=0 ;j<s ;j++) sumcol+=grid[j+x][y+i];
  
			// if sum of row or column is not equal to precomputed diagonal sum, return 1
            if(sumcol!=sum || sumrow!=sum) return 1;
        }
		
		//finally return the size itself as it is a magic square and all rows , columns and diagonals' sum are equal
        return s;
    }
    
    int largestMagicSquare(vector<vector<int>>& grid) {
        
		int n = grid.size() , m  = grid[0].size() ;
        int ans=1;
		
        for(int i=0 ;i<n ;i++){
		// row index i
            for(int j=0 ;j<m ;j++){
			//column index j
                for(int k=1 ;k<=min(m,n) ;k++){
				//size k
                    int temp = check(grid,i,j,k);
					//updating answer if we get greater size magic square 
                    ans=max(ans,temp);
                }
            }
        }
		//returning maximum size of magic square
        return ans;
    }
};
