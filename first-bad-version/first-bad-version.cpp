// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int solve(int n,int low,int high)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isBadVersion(mid))
                high =mid-1;
            else 
                low=mid+1;
           
                
        }
        return low;
    }
    int firstBadVersion(int n) {
        int low =1,high=n;
        return solve(n,low,high);
        
    }
};