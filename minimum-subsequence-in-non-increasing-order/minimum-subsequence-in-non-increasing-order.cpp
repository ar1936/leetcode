// MY try

// class Solution {
// public:
//     vector<int> minSubsequence(vector<int>& nums) {
//         sort(nums.begin(),nums.end(),greater<int>());
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }
//         vector<int>v;
//         int temp=0,i=nums.size()-1;
//         for(;i>=0;i--){
//             temp+=nums[i];
//             if(temp==sum/2)
//                 i--;
//             if(temp>=sum/2)
//                 break;
//         }
//         for(int j=0;j<i;j++){
//             v.push_back(nums[j]);
//         }
//                 // sort(nums.begin(),nums.end(),greater<int>());
//         return v;
//     }
// };



class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum=0,newsum=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        sort(nums.begin(),nums.end(),std::greater<>());
        for(int i=0;i<nums.size();i++)
        {
            newsum+=nums[i];
            sum=sum-nums[i];
            ans.push_back(nums[i]);
            if(newsum>sum)
                break;
        }
        sort(ans.begin(),ans.end(),std::greater<>());
        return ans;
    }
};