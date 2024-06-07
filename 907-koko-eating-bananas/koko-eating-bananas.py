class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def solve(mid):
            sum = 0
            for p in piles:
                sum+=(p//mid + int(p%mid!=0))
            return sum<=h
        low = 1
        high = max(piles)
        while low<high:
            mid = low + (high-low)//2
            if solve(mid):
                high = mid
            else:
                low = mid+1
        return low