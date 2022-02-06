class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int>ans,odd,even;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        reverse(even.begin(),even.end());
        int j=0,k=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                nums[i]=odd[j++];
            else
                nums[i]=even[k++];
        }
        return nums;
    }
};