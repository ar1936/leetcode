// class Solution {
// public:
//     // int solve(vector<int>nums,int prev,int i)
//     // {
//     //     int n=nums.size();
//     //     vector<int>t(n+1,-1);
//     //     if(t[i]!=-1)
//     //         return t[i];
//     //     if(i==nums.size())
//     //         return 0;
//     //     int taken=0;
//     //     if(nums[i]>prev)
//     //     {
//     //         t[i]=solve(nums,nums[i],i+1)+1;
//     //     }
//     //     t[i]=solve(nums,prev,i+1);
//     //     return max(t[n-1],t[n]);
//     // }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> t (n+1,1);
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<i;j++)
//             {
//                 if(nums[i]>nums[j])
//                     t[i]=max(t[i],1+t[j]);
//             }
//         }
//         int ans=0;
//         for(int i=0;i<n;i++)
//             ans=max(t[i],ans);
//         return ans;
        
        
//         // return solve(nums,INT_MIN,0);
//     }
// };




class Solution  {

public:

	int lengthOfLIS(vector<int>& nums) { 

		int k = 0;
		for (int i=0; i<nums.size(); i++) {
			int pos   = lower_bound(nums.begin(), nums.begin()+k, nums[i]) - nums.begin();    
			nums[pos] = nums[i];
			if (k == pos) {
				k = pos + 1;
			}
		}

		return k;

	}

};