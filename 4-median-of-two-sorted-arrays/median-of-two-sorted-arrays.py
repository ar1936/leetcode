class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1)>len(nums2):
            return self.findMedianSortedArrays(nums2,nums1)
        n, m = len(nums1), len(nums2)
        left = 0
        right = n
        while left<=right:
            IA = (left+right)//2
            IB = (m+n+1)//2 - IA
            maxLA = float("-inf") if IA == 0 else nums1[IA-1]
            minRA = float("inf") if IA == n else nums1[IA]
            maxLB = float("-inf") if IB == 0 else nums2[IB -1]
            minRB = float("inf") if IB == m else nums2[IB]

            if maxLA <= minRB and maxLB <= minRA:
                if (m+n)%2==0:
                    return (max(maxLA,maxLB) + min(minRA, minRB))/2
                else:
                    return max(maxLA, maxLB)
            elif maxLA>minRB:
                right = IA -1 
            else:
                left = IA + 1