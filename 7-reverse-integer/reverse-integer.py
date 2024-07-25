class Solution:
    def reverse(self, x: int) -> int:
        if x> 2**31 -1 or x< -2**31:
            return 0 
        sign = True # positive
        if x<0:
            sign = False
            x=-x
        ans = 0
        max_decimal = 1
        while max_decimal<=x:
            max_decimal *= 10
        max_decimal//=10
        while max_decimal:
            ans += (x%10) * max_decimal
            x//=10
            max_decimal //= 10
        if sign == False:
            ans = -ans
        if ans> 2**31 -1 or ans< -2**31:
            return 0 
        return ans