class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        lo = 0
        hi = len(nums) - 1
        
        # Binary search loop
        while lo <= hi:
            # Find the middle index
            mid = lo + (hi - lo) // 2
            
            # Ensure mid is even so it points to the first element of a pair
            if mid % 2 == 1:
                mid -= 1
            
            # Check if the pair starts at mid (i.e., nums[mid] == nums[mid + 1])
            if mid + 1 < len(nums) and nums[mid] == nums[mid + 1]:
                # If they match, the single element is to the right, skip this pair
                lo = mid + 2
            else:
                # If they don't match, the single element is to the left or at mid
                hi = mid - 1
        
        # At the end of the loop, lo points to the single element
        return nums[lo]
