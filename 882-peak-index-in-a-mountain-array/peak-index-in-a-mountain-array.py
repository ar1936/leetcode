class Solution:
    def peakIndexInMountainArray(self, nums: List[int]) -> int:
        # Get the length of the array
        n = len(nums)
        
        # Initialize low and high pointers for binary search
        low, high = 0, n-1
        
        # Edge case: if there's only one element or the first element is a peak
        if n == 1 or nums[0] > nums[1]:
            return 0
        
        # Edge case: if the last element is a peak
        if nums[-1] > nums[-2]:
            return n-1
        
        # Binary search loop
        while low <= high:
            # Calculate the middle index to avoid overflow
            mid = ((high-low)//2) + low
            
            # Check if the peak is in the right half
            if nums[mid] < nums[mid+1]:
                low = mid + 1
            
            # Check if the peak is in the left half
            elif nums[mid] < nums[mid-1]:
                high = mid - 1
            
            # If neither, the current element is a peak
            else:
                return mid

