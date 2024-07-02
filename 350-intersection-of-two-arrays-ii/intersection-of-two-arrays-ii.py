class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        mp = defaultdict(int)
        for num in nums1:
            mp[num]+=1
        for num in nums2:
            if mp[num]>0:
                ans.append(num)
            mp[num]-=1
        return ans