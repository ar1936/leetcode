// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n=prices.size();
//         int buy=prices[0];
//         int sell=0;
//         int ans=0;
//         for(int i=1;i<n;i++){
//             if(prices[i]>=prices[i-1]){
//                 sell=prices[i];
//             }
//             else if(prices[i]<prices[i-1]){
//                 if((sell-buy-fee)>0){
//                     ans+=(sell-buy-fee);
//                 }
//                 buy=prices[i];
//                 sell=buy;
//             }
//         }
//         if((sell-buy-fee)>fee){
//             ans+=(sell-buy-fee);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int>buy(n,INT_MIN),sell(n);
        buy[0]=-prices[0];
        sell[0]=0;
        for(int i=1;i<n;i++){
            buy[i]=max(sell[i-1]-prices[i],buy[i-1]);
            sell[i]=max(prices[i]+buy[i-1]-fee,sell[i-1]);
        }
        return sell[n-1];
    }
};
