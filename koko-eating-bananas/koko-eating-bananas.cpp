class Solution {
    bool solve(vector<int>&nums,int mid,int h){
        int min_hours=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0)
                min_hours+=nums[i]/mid;
            else
                min_hours+=nums[i]/mid+1;
        }
        if(min_hours>h)
                return false;
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int lo=0,hi=1e9+1e5;
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=piles[i];
        }
        if(sum<=h)
            return 1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(solve( piles,mid,h))
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};



