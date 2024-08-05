class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # ans = -10**9
        s = sum(nums[:k])
        ans = s/k

        for i in range(k,len(nums)):
            s+=(nums[i] - nums[i-k])
            ans = max(s/k,ans)
        ans = max(s/k,ans)
        return ans 
