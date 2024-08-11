class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        ans = 0
        def solve(m):
            count = 0 
            for p in piles:
                if p<=m:
                    count+=1
                else:
                    count += p//m
                    if p%m!=0:
                        count += 1
            return count<=h
        while l<=r:
            mid = (l+r)//2
            if(solve(mid)):
                r = mid - 1
                ans = mid  
            else:
                l = mid + 1
        return ans
