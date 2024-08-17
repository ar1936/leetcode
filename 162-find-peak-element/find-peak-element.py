class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        if len(nums) < 3:
            if len(nums) == 1:
                return 0
            else:
                return 1 if nums[0] < nums[1] else 0

        while left <= right:
            mid = left + (right - left) // 2

            # Edge cases to handle comparisons at array boundaries
            if (mid == 0 or nums[mid] > nums[mid - 1]) and (mid == len(nums) - 1 or nums[mid] > nums[mid + 1]):
                return mid
            elif mid > 0 and nums[mid] < nums[mid - 1]:  # Move to the left half
                right = mid - 1
            else:  # Move to the right half
                left = mid + 1

        return -1  # This should technically never be reached if there's always a peak
