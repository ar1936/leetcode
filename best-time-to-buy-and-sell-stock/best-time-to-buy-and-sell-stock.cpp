class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int temp=0,ans=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(ans>prices[i])
                ans=prices[i];
            else 
                temp=max(temp,prices[i]-ans);
        }
        return temp;
            

    }
};