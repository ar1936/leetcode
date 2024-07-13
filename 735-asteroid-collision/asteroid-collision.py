class Solution:
    def asteroidCollision(self, nums: List[int]) -> List[int]:
        st = []
        for num in nums:
            while len(st) and (num<0<st[-1]):
                if st[-1] > -num:
                    break
                elif st[-1]<-num:
                    st.pop()
                else:
                    st.pop()
                    break
            else:
                st.append(num)
        return st