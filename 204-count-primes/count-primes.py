class Solution:
    def countPrimes(self, n: int) -> int:
        if n<=1:
            return 0
        prime = [True]*n 
        prime[0] = False
        prime[1] = False
        i = 2
        while i*i<n:
            if prime[i]:
                for j in range(i*i, n, i):
                    prime[j] = False
            i+=1
        return sum(prime)