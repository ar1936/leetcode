class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        i = 0
        while i*i<=c:
            num = int(math.sqrt(c - i*i))
            if c == num**2 + i**2:
                return True
            i+=1
        return False