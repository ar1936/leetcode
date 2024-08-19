class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1
        ans = 0
        sum = 0
        for i in range(len(nums)):
            sum+=nums[i]
            mod_val = sum%k 
            ans += mp[mod_val]
            mp[mod_val]+=1
        return ans