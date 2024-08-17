class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l = 0
        r = len(arr) - 1  # Adjust the right boundary to len(arr) - 1

        while l <= r:
            mid = (l + r) // 2

            if arr[mid] < arr[mid + 1]:  # Peak is to the right
                l = mid + 1
            else:  # Peak is to the left or is at mid
                r = mid - 1

        # At the end of the loop, l will be the peak index
        return l
