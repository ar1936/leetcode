class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.size());
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                if(prices[i]>=prices[j]){
                    ans[i]=prices[i]-prices[j];
                    break;
                }
                else
                    ans[i]=prices[i];
            }
        }
        ans.back()=prices.back();
        return ans;
    }
};