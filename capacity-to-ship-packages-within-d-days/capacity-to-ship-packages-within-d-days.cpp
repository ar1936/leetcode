class Solution {
bool solve(vector<int>weights,int mid,int days){
    int count=0,sum=0;
    for(int i=0;i<weights.size();i++){
        if(sum+weights[i]>mid){
            count++;
            sum=weights[i];
        }
        else
            sum+=weights[i];
    }
     return count+1<=days;
}
    public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=0,hi=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            lo=max(lo,weights[i]);
        }
        if(sum<=days){
            return 1;
        }
        hi=sum;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(solve(weights,mid,days))
                hi=mid;
            else
                lo=mid+1;
        }
        return lo;
    }
};

