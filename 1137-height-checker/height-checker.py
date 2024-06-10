class Solution:
    def heightChecker(self, h: List[int]) -> int:
        v = sorted(h)
        ans = 0
        for i in range(len(h)):
            if h[i] != v[i]:
                ans+=1
        return ans