class Solution:
    def search(self, nums: List[int], target: int) -> int:
        def binary_search(arr):
            l = 0
            h = len(arr)-1
            while(l<=h):
                mid = l+(h-l)//2
                if arr[mid]==target:
                    return mid
                elif arr[mid]>target:
                    h = mid-1
                else:
                    l = mid + 1
            return -1
        low = 0
        high = len(nums)-1
        while(low<high):
            mid = low+(high-low)//2
            if nums[mid]>nums[high]:
                low = mid+1
            else:
                high = mid
        left_search = binary_search(nums[:low])
        right_search = binary_search(nums[low:])
        return low + right_search if right_search != -1 else left_search