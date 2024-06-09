class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefix_sum = 0
        reminder= [0]*k
        reminder[0] = 1
        ans = 0
        for i,num in enumerate(nums):
            prefix_sum = (num + k +prefix_sum)%k
            ans+= reminder[prefix_sum]
            reminder[prefix_sum] += 1
        return ans
