class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        arr = []
        for num1, num2 in zip(nums1,nums2):
            arr.append(num1-num2)
        arr.sort()
        ans = 0
        n = len(arr)
        for i in range(n):
            if arr[i] > 0:
                ans += n - i - 1
            else:
                j = bisect_right(arr, -arr[i], i + 1, n)
                ans += n - j
        return ans