// explaination -> https://www.youtube.com/watch?v=GY0O57llkKQ&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=33&ab_channel=PepcodingPepcoding

// After dry run you will understand this code;




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int n=prices.size();
        vector<int>buy(n);
        vector<int>sell(n);
        vector<int>cool(n);
        buy[0]=-prices[0];
        sell[0]=INT_MIN;
        cool[0]=0;
        for(int i=1;i<n;i++){
            buy[i]=max(buy[i-1],cool[i-1]-prices[i]);
            sell[i]=buy[i-1]+prices[i];
            cool[i]=max(sell[i-1],cool[i-1]);
        }
        return max(sell[n-1],cool[n-1]);
    }
};