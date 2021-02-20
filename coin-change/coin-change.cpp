class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size=coins.size();
        int  t[size+1][amount+1];
        for(int i=0;i<size+1;i++)
            t[i][0]=0;
        for(int j=0;j<amount+1;j++)
        {
            t[0][j]=INT_MAX-1;
        }
        for(int j=1;j<amount+1;j++)
        {
            if(j%coins[0]==0)
                t[1][j]=j/coins[0];
            else 
                t[1][j]=INT_MAX-1;
        }
        for(int i=1;i<size+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(j<coins[i-1])
                    t[i][j]=t[i-1][j];
                else 
                    t[i][j]=min(t[i-1][j],t[i][j-coins[i-1]]+1);
            }
        }
        if(t[size][amount]==INT_MAX-1)
            return -1;
        return t[size][amount];
        
    }
};

// private int knapsack(int[] coins, int sum, int n) {
// 		  // Creating array which stores subproblems' solutions
// 		  double[][] arr = new double[coins.length + 1][sum + 1];

// 		  // Initialising first row with +ve infinity
// 		  for(int j = 0; j < sum+1; j++){
// 			  arr[0][j] = Double.POSITIVE_INFINITY;
// 		  }	      
	    
// 		  // Initialising first column with 0
// 		  for(int i = 1; i < coins.length+1; i++){
// 			  arr[i][0] = 0;
// 		  }

// 		  // Implementing the recursive solution
// 		  for(int i = 1; i < coins.length+1; i++){
// 			  for(int j = 1; j < sum+1; j++){
// 				  if(coins[i - 1] <= j)
// 					  arr[i][j] = Math.min(1 + arr[i][j - coins[i - 1]], arr[i - 1][j]);
// 				  else
// 					  arr[i][j] = arr[i - 1][j];
// 			  }
// 		  }