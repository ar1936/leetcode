class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        median = 0
        if n%2:
            median = nums[n//2]
        else:
            median = max(nums[n//2], nums[n//2-1])
        if median == k:
            return 0
        for i in range(n):
            if(i<n//2):
                if nums[i]>k:
                    ans+=(nums[i]-k)
            elif(i==n//2):
                ans+=abs(nums[i]-k)
            else:
                if nums[i]<k:
                    ans+=(k-nums[i])
        return ans