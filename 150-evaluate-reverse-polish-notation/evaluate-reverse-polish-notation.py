class Solution:
    def evalRPN(self, s: List[str]) -> int:
        st = []
        for c in s:
            if c in ['+', '-', "/", "*"]:
                num1 = st.pop()
                num2 = st.pop()
                if c == '+':
                    st.append(num1+num2)
                if c == '-':
                    st.append(num2-num1)
                if c == '*':
                    st.append(num1*num2)
                if c == '/':
                    st.append(int(num2/num1))
            else:
                st.append(int(c))
        return st.pop()
