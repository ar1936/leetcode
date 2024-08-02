class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        gap = sum(nums)  # Total number of 1's in the array
        if gap == 0:  # If there are no 1's, no swaps are needed
            return 0
        
        n = len(nums)
        nums = nums + nums  # Extend the array to handle the circular nature
        tmp = sum(nums[:gap])  # Sum of the first 'gap' elements (initial window sum)
        ans = gap - tmp  # Initial number of swaps needed
        
        # Slide the window across the array
        for i in range(1, n):
            tmp += nums[i + gap - 1] - nums[i - 1]
            ans = min(ans, gap - tmp)
        
        return ans