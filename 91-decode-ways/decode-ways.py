class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [-1]*n
        # Define a recursive function to solve the problem
        def solve(ind):
            # If we have reached the end of the string, return 1 to signify a valid decoding
            if ind >= n:
                return 1
            
            if dp[ind]!=-1:
                return dp[ind]
            # Initialize result
            res = 0
            
            # Check if the current digit is valid (not '0')
            if s[ind] != '0':
                res += solve(ind + 1)  # Move to the next digit
            
            # Check if we can form a valid two-digit number
            if ind + 1 < n and (s[ind] == '1' or (s[ind] == '2' and s[ind + 1] <= '6')):
                res += solve(ind + 2)  # Move two digits forward
            dp[ind] = res
            return dp[ind]
        
        # Start the recursion from the beginning of the string
        return solve(0)
