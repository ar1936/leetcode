class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),ans=0,temp=prices[0];
        if(n==1)
            return 0;
        for(int i=0;i<n;i++){
            if(temp>prices[i])
                temp=prices[i];
            else
                ans=max(ans,prices[i]-temp);
        }
        return ans;
    }
};