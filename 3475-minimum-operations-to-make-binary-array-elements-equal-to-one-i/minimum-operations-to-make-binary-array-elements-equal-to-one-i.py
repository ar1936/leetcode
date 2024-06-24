class Solution:
    def minOperations(self, A: List[int]) -> int:
        K = 3
        cur, res, n = 0, 0, len(A)
        for i in range(len(A)):
            if i >= K and A[i - K] > 1:
                A[i - K] -= 2
                cur -= 1
            if cur & 1 ^ A[i] == 0:
                if i + K > len(A):
                    return -1
                A[i] += 2
                cur += 1
                res += 1
        return res