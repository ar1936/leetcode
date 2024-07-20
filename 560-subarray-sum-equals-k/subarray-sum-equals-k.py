class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        sum = 0
        mp = defaultdict(int)
        mp[0] = 1
        for num in nums:
            sum += num 
            ans += mp[sum-k] 
            mp[sum]+=1
        return ans