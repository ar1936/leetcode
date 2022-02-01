class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_previous_day=prices[0],max_profit=0;
        for(int i=1;i<prices.size();i++){
            max_profit=max(max_profit,prices[i]-buy_previous_day);
            buy_previous_day=min(buy_previous_day,prices[i]);
        }
        return max_profit;
    }
};


