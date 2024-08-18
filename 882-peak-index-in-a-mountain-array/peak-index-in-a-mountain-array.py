from typing import List

class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr) - 1

        while l <= r:
            mid = (l + r) // 2

            # - (mid == 0): This ensures we don't go out of bounds on the left side (first element).
            # - (arr[mid] > arr[mid - 1]): Checks if the mid element is greater than its left neighbor.
            # - (mid == len(arr) - 1): This ensures we don't go out of bounds on the right side (last element).
            # - (arr[mid] > arr[mid + 1]): Checks if the mid element is greater than its right neighbor.
            if (mid == 0 or arr[mid] > arr[mid - 1]) and (mid == len(arr) - 1 or arr[mid] > arr[mid + 1]):
                return mid  
            elif mid > 0 and arr[mid - 1] > arr[mid]:
                r = mid - 1  
            else:
                l = mid + 1  
        return l 
