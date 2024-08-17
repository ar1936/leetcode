class Solution:
    def findMin(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums) - 1
        
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            
            # If we find the minimum
            if mid > 0 and nums[mid] < nums[mid - 1]:
                return nums[mid]
            
            # Check which half to search
            if nums[mid] > nums[hi]:
                lo = mid + 1
            else:
                hi = mid - 1
        
        # When the loop ends, lo should point to the minimum element
        return nums[lo]
