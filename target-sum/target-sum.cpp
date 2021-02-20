class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0,val=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]==0)
                count++;
        }
        if(sum<S)
            return 0;
        
        if((S+sum)%2!=0)
            return 0;
          
        
        val=(sum+S)/2;
        int n=nums.size();
        int t[n+1][val+1];
        for(int j=0;j<val+1;j++)
        {
            t[0][j]=0;
            
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=1;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<val+1;j++)
            {
                if(nums[i-1]==0)
                    t[i][j]=t[i-1][j];
                else if(j<nums[i-1])
                    t[i][j]=t[i-1][j];
                else if(j>=nums[i-1])
                    t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
            }
        }
        return pow(2,count)*t[n][val];
    }
};