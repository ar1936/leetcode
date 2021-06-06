class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int cur = nums[i];
                int streak=1;
                while(s.find(cur+1)!=s.end())
                {
                    cur+=1;
                    streak++;
                }
                longest = max(longest,streak);
            }
        }
        return longest;
    }
};