class Solution:
    # def kthGrammar(self, n: int, k: int) -> int:
    #     if n == 1:
    #         return 0
    #     number_of_row = 2**(n-1)
    #     midpoint = number_of_row//2

    #     if k>midpoint:
    #         return 1 - self.kthGrammar(n-1,k-midpoint)
    #     return self.kthGrammar(n-1,k)
    def kthGrammar(self, n: int, k: int) -> int:
        if k == 1:
            return 0
        elif k % 2 == 1:
            return self.kthGrammar(n - 1, (k + 1) // 2)  # If k is odd, return previous val
        else:
            return 1 - self.kthGrammar(n - 1, k // 2)    # If k is even, return previous val flipped

