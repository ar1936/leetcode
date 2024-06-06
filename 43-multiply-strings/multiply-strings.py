class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        
        n, m = len(num1), len(num2)
        result = [0] * (n + m)

        # Multiply each digit from the rightmost side
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                # Calculate product of the current digits
                product = int(num1[i]) * int(num2[j])
                # Position in the result array
                p1, p2 = i + j, i + j + 1
                # Add the product to the current position, taking care of the carry
                total = product + result[p2]
                result[p2] = total % 10
                result[p1] += total // 10
        result_str = ''.join(map(str, result))
        return result_str.lstrip('0')
