class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        memo = {}
        
        def dp(ind, holding):
            # Base case: If we've gone through all the days
            if ind >= len(prices):
                return 0
            
            # Check if we've already solved this subproblem
            if (ind, holding) in memo:
                return memo[(ind, holding)]
            
            # If we are holding a stock, we have two choices: sell it or keep holding it
            if holding:
                sell = prices[ind] + dp(ind + 2, False)  # Sell and skip one day (cooldown)
                keep_holding = dp(ind + 1, True)  # Move to the next day without selling
                profit = max(sell, keep_holding)
            else:
                # If we are not holding a stock, we have two choices: buy it or do nothing
                buy = -prices[ind] + dp(ind + 1, True)  # Buy and hold the stock
                do_nothing = dp(ind + 1, False)  # Move to the next day without buying
                profit = max(buy, do_nothing)
            
            # Save the result in the memo dictionary
            memo[(ind, holding)] = profit
            return profit
        
        # Start from day 0 without holding any stock
        return dp(0, False)