class Solution:
    def calculate(self, s: str) -> int:
        length = len(s)
        if length == 0:
            return 0
        
        current_number = 0
        last_number = 0
        result = 0
        sign = '+'
        
        for i in range(length):
            current_char = s[i]
            
            if current_char.isdigit():
                current_number = (current_number * 10) + int(current_char)
            
            if not current_char.isdigit() and not current_char.isspace() or i == length - 1:
                if sign == '+' or sign == '-':
                    result += last_number
                    last_number = current_number if sign == '+' else -current_number
                elif sign == '*':
                    last_number = last_number * current_number
                elif sign == '/':
                    last_number = int(last_number / current_number)
                
                sign = current_char
                current_number = 0
        
        result += last_number
        return result
