class Solution:
    def distinctSubseqII(self, s: str) -> int:
        mod = 10**9 + 7
        n = len(s)
        
        # DP array where dp[i] represents the number of distinct subsequences of s[:i]
        dp = [0] * (n + 1)
        dp[0] = 1  # There's one way to form an empty subsequence
        
        # Dictionary to keep track of the last occurrence of each character
        last_seen = {}
        
        for i in range(1, n + 1):
            char = s[i - 1]
            
            # The number of distinct subsequences considering the current character
            dp[i] = (2 * dp[i - 1]) % mod
            
            # If the character has been seen before, subtract the subsequences
            # that were counted due to the previous occurrence of the same character
            if char in last_seen:
                dp[i] = (dp[i] - dp[last_seen[char] - 1]) % mod
            
            # Update the last occurrence of the current character
            last_seen[char] = i
        
        # The answer is dp[n] minus 1 (to exclude the empty subsequence)
        return (dp[n] - 1 + mod) % mod
