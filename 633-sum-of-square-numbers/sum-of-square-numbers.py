class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # if c == 0:
        #     return True
        for i in range(0,100000):
            if c>=i*i:
                num = int(math.sqrt(c - i*i))
                if c == num**2 + i**2:
                    return True
        return False