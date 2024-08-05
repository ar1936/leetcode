from typing import List
from bisect import bisect_left, insort

class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        # Getting the dimensions of the matrix
        num_rows, num_cols = len(matrix), len(matrix[0])
        
        # Initializing the maximum sum
        max_sum = -float('inf')
        
        # Iterate over all possible left column indices
        for left_col in range(num_cols):
            
            # Initialize the temporary row sums
            row_sums = [0] * num_rows
            
            # Iterate over all possible right column indices
            for right_col in range(left_col, num_cols):
                
                # Update the row sums for the current column range
                for row in range(num_rows):
                    row_sums[row] += matrix[row][right_col]
                
                # Apply Kadane's algorithm to find the maximum sum of a subarray with sum <= k
                max_sum = max(max_sum, self.kadane_max_sum(row_sums, k))
        
        # Return the maximum sum found
        return max_sum
    
    def kadane_max_sum(self, nums: List[int], k: int) -> int:
        # Function to apply Kadane's algorithm with constraint sum <= k
        max_sum = -float('inf')
        cum_sum = 0
        prefix_sums = [0]
        
        for num in nums:
            cum_sum += num
            # Find the smallest prefix sum such that cum_sum - prefix_sum <= k
            index = bisect_left(prefix_sums, cum_sum - k)
            if index < len(prefix_sums):
                max_sum = max(max_sum, cum_sum - prefix_sums[index])
            # Insert the current cumulative sum into the prefix sums list
            insort(prefix_sums, cum_sum)
        
        return max_sum
