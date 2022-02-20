class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2==1)
            return {};
        if(finalSum==2)
            return {2};
        if(finalSum==4)
            return {4};
        vector<long long>ans;
        int j=1;
        set<long long>st;
        while(finalSum){
            if(finalSum/2==2*j)
            {
                ans.push_back(finalSum);
                finalSum=0;
            }
            else if(finalSum/2<j){
                ans.push_back(finalSum);
                finalSum=0;
            }
            else if(finalSum-2*j>=0){
                ans.push_back(2*j);
                st.insert(2*j);
                finalSum-=2*j;
            }
            j++;
        }
        if(ans.back()<ans[ans.size()-2])
        {
            ans[ans.size()-2]=ans.back()+ans[ans.size()-2];
            ans.pop_back();
        }
        return ans;
    }
};


