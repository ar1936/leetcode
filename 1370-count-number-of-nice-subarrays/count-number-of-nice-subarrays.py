class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        for i in range(len(nums)):
            if nums[i]%2==1:
                nums[i] = 1
            else:
                nums[i] = 0
        sum = 0
        ans = 0
        mp= defaultdict(int)
        mp[0] = 1
        for i in range(len(nums)):
            sum+=nums[i]
            mp[sum] += 1    
            ans += mp[sum-k]
        return ans