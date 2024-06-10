class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        pre = []
        suf = []
        p1 = 1
        p2 = 1
        ans = []
        for i in range(len(nums)):
            p1 *= nums[i]
            p2 *= nums[len(nums)-1-i]
            pre.append(p1)
            suf.append(p2)
        suf = suf[::-1]
        for i in range(len(nums)):
            ans.append((pre[i-1] if i>0 else 1)*(suf[i+1] if i<len(nums)-1 else 1))
        return ans