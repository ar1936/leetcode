class Solution:
    def evalRPN(self, nums: List[str]) -> int:
        s = []
        if len(nums)==1:
            return int(nums[0])
        for i in range(len(nums)):
            s.append(nums[i])
            while(s[-1] in ['+','-','/','*']):
                sign = s.pop()
                num2 = int(s.pop())
                num1 = int(s.pop())
                if sign == '+':
                    tmp_ans = num1+num2
                elif sign == '-':
                    tmp_ans = num1 - num2
                elif sign == '*':
                    tmp_ans = num1*num2
                else:
                    tmp_ans = int(num1/num2)
                s.append(tmp_ans)
        return s[-1]