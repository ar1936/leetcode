class Solution:
    def findPeakElement(self, arr: List[int]) -> int:
        l = 0
        r = len(arr) - 1  # Adjust the right boundary to len(arr) - 1

        # Edge case: if there's only one element or the first element is a peak
        if r+1 == 1 or arr[0] > arr[1]:
            return 0
        
        # Edge case: if the last element is a peak
        if arr[-1] > arr[-2]:
            return r
        
        while l <= r:
            mid = (l + r) // 2

            if arr[mid] < arr[mid + 1]:  # Peak is to the right
                l = mid + 1
            else:  # Peak is to the left or is at mid
                r = mid - 1

        # At the end of the loop, l will be the peak index
        return l
