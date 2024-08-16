class Solution:
    def findNthDigit(self, n: int) -> int:
        # Initialize variables to track the current digit length, count of numbers, and the starting number
        length, count, start = 1, 9, 1
        
        # We continue looping until we identify the correct length of digits where the nth digit is located
        while n > length * count:
            # Example with n = 8977384871:
            # First iteration:
            # n = 8977384871, length = 1, count = 9
            # n > 1 * 9 => n -= 9, n = 8977384871 - 9 = 8977384862
            n -= length * count
            
            # Increase the digit length to 2 (considering 2-digit numbers next)
            length += 1  # length = 2
            
            # Update the count to reflect the number of digits in 2-digit numbers
            count *= 10  # count = 9 * 10 = 90
            
            # Update the starting number to 10 (first 2-digit number)
            start *= 10  # start = 1 * 10 = 10
        
        # Repeat the process for 2-digit, 3-digit, ... until the correct range is found:
        # After several iterations:
        # n will be reduced enough to find the exact digit range
        # Let's say n becomes a much smaller value within the range of, for example, 8-digit numbers.
        # At some point:
        # length = 8, start = 10000000 (starting 8-digit number), count = 90000000 (number of 8-digit numbers)
        
        # Find the specific number in the identified range
        start += (n - 1) // length
        # Example, start might become a specific large 8-digit number after computation
        
        # Extract the specific digit from that number
        return int(str(start)[(n - 1) % length])
