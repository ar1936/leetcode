class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=prices[0];
        int sell=prices[0];
        int ans=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                sell=prices[i];
            }
            else if (prices[i]<prices[i-1]){
                ans+=(sell-buy);
                buy=prices[i];
                sell=prices[i];
                
            }
        }
        ans+=sell-buy;
        return ans;
    }
};