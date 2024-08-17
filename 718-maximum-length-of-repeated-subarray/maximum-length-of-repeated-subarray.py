class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        def solve(nums1, nums2):
            n = len(nums1)
            m = len(nums2)
            ans = 0
            
            # Try all possible alignments of nums1 and nums2
            for i in range(n):
                l = 0
                for j in range(min(m, n - i)):
                    if nums1[i + j] == nums2[j]:
                        l += 1
                        ans = max(ans, l)
                    else:
                        l = 0
            
            return ans
        
        # Check both alignments
        return max(solve(nums1, nums2), solve(nums2, nums1))
