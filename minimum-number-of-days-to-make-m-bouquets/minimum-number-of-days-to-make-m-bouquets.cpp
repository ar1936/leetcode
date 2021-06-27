

class Solution {
    bool solve(int mid,vector<int>&nums,int m,int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
            }
            else
            {
                count=0;
            }
            if(count==k){
                m--;
                count=0;
            }
            if(m==0){
                return true;
            }
        }
        return false;
    }
public:
    int minDays(vector<int>& nums, int m, int k) {
        
        int lo=1e6,hi=0,n=nums.size();
        if(m*k>n){
            return -1;
        }
        for(int i=0;i<n;i++){
            lo=min(lo,nums[i]);
            hi=max(hi,nums[i]);
        }
        
        while(lo<hi){
        
            int mid=lo+(hi-lo)/2;

            if(solve(mid,nums,m,k))                  
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};

