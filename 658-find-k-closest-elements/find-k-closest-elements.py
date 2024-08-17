class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # Initialize binary search bounds
        left = 0
        right = len(arr) - k
        
        # Binary search against the criteria described
        while left <= right:
            mid = (left + right) // 2
            
            # Ensure mid+k doesn't exceed the array bounds
            if mid + k < len(arr) and x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid - 1

        return arr[left:left + k]
