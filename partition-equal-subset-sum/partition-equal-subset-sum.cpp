class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

        }
        if(sum%2!=0)
            return false;
        else 
            ans=sum/2;
        int n=nums.size();
        bool t[n+1][ans+1];
        
        for(int j=0;j<ans+1;j++)
        {
            t[0][j]=false;
        }
        
        for(int i=0;i<n+1;i++)
        {
            t[i][0]=true;
        }
        
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<ans+1;j++)
            {
                if(j<nums[i-1])
                    t[i][j]=t[i-1][j];
                else if (j>=nums[i-1])
                    t[i][j]=t[i-1][j]||t[i-1][j-nums[i-1]];
                
            }
        }
        return t[n][ans];
        
        
    }
};