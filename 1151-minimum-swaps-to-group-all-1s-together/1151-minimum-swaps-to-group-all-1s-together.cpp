class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0,ans=INT_MAX,count=0;
        for(auto x:nums){
            if(x)
                k++;
        }
        for(int i=0;i<k;i++){
            if(nums[i])
                count++;
        }
        cout<<count<<' ';
        ans=min(ans,k-count);
        for(int i=k;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            if(nums[i-k]==1)
            {
                count--;
            }
            ans=min(ans,k-count);
            cout<<count<<' ';
        }
        cout<<endl;
        return ans;
    }
};