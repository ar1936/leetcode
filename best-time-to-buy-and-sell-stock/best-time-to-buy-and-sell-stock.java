class Solution {
    public int maxProfit(int[] prices) {
        int ans=0,buy_price=prices[0];
        for(int i=1;i<prices.length;i++){
            ans=Math.max(ans,prices[i]-buy_price);
            buy_price=Math.min(buy_price,prices[i]);
        }
        return ans;
    }
}