class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        count = 0
        # Try every possible length of the sequence from 1 to n
        k = 1
        while (k * (k + 1)) // 2 <= n:
            # Check if there exists a sequence of length k that sums to n
            if (n - (k * (k + 1)) // 2) % k == 0:
                count += 1
            k += 1
        return count