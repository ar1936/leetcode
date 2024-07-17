class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            n = -n
            x = 1/x
        ans = 1
        while n>=1:
            if n%2:
                ans*=x
            x*=x
            n//=2
        return ans