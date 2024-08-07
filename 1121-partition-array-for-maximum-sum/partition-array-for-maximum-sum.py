class Solution:
    def solve(self, i: int, k: int, arr: List[int], dp: List[int]) -> int:
        if i >= len(arr):
            return 0
        
        j = i + k
        if j > len(arr):
            j = len(arr)
        
        if dp[i] != -1:
            return dp[i]
        
        max_ans = float('-inf')
        max_ele = float('-inf')
        for x in range(i, j):
            max_ele = max(arr[x], max_ele)
            temp_ans = max_ele * (x - i + 1) + self.solve(x + 1, k, arr, dp)
            if temp_ans > max_ans:
                max_ans = temp_ans
        
        dp[i] = max_ans
        return max_ans
    
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        dp = [-1] * len(arr)
        return self.solve(0, k, arr, dp)
