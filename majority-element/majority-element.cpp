class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int m=0;
        if(nums.size()%2==0)
            m=nums.size()/2;
        else
            m=(nums.size()+1)/2;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>=m) 
                return nums[i];
        }
        return 0;
        
        
    }
};