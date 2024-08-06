class Solution:
    def superEggDrop(self, k: int, n: int) -> int:
        def canDo(moves: int, eggs: int, floors: int) -> bool:
            total = 0
            for i in range(1, eggs + 1):
                total += comb(moves, i)
                if total >= floors:
                    return True
            return total >= floors

        lo, hi = 1, n
        while lo < hi:
            mid = (lo + hi) // 2
            if canDo(mid, k, n):
                hi = mid
            else:
                lo = mid + 1

        return lo

# Helper function for combinations
from math import comb


# Input: k = 1, n = 2
# Output: 2
# Explanation: 
# Drop the egg from floor 1. If it breaks, we know that f = 0.
# Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
# If it does not break, then we know f = 2.
# Hence, we need at minimum 2 moves to determine with certainty what the value of f is.


# Example 2:

# Input: k = 2, n = 6
# Output: 3
# # in this problem we have 2 variable. first minium number of moves and number of floor 
# if we check all the floor from 1 to n then what happen ???

# we have 2 choice at every case right ?? egg will broke or not broke ??


# what happen if we choose floor height h and it broken that means our answer lies b/w 0 to h. that means we can apply binary search 

# l= 0 hi = 6 
# mid = 3 
# # broke at 3 then out answer in (0,3) that means right = mid -1 
# lo = 0 hi = 2
# mid = 1
# # broke then answer lies between (0,0) so 
# f1 =>

# Example 3:

# Input: k = 3, n = 14
# Output: 4

