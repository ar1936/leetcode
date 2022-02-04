class Solution {
public:
    // int findMaxLength(vector<int>& nums) {
    //     int n=nums.size(),ans=0;
    //     for(int i=1;i<n;i++){
    //         nums[i]=nums[i]+nums[i-1];
    //         if(2*nums[i]<=i+1){
    //             ans=max(2*nums[i],ans);
    //         }
    //     }
    //     for(auto x:nums){
    //         cout<<x<<" ";
    //     }
    //     return ans;
    // }
    
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
		
		// map stores pairs {a, i} where a = prefix sum of subarray and i = ending index of that subarray
        unordered_map<int,int> mp;
        int pre = 0, res = 0;
        
		// replace 0s with -1
        for(int i = 0; i < n; i++)
            if(nums[i] == 0) nums[i] = -1;
        
        for(int i = 0; i < n; i++){
            pre += nums[i];
			
			// if current subarray has sum 0 then result becomes length of this subarray
            if(pre == 0) res = i+1;
			
			// if this pair is not present already
            if(mp.find(pre) == mp.end()) mp.insert({pre, i});
            
			// result is maximum of previous result and length of this subarray (current index - index of subarray having same prefix sum)
			else res = max(res, i-mp[pre]);
        }
        
		// if no such subarray is found then res will not get updated and it will return 0
        return res;
    }
};