from typing import List

class Solution:
    def asteroidCollision(self, nums: List[int]) -> List[int]:
        st = []
        for num in nums:
            # Process collision only if there's a potential collision (num < 0 and last in stack > 0)
            while st and num < 0 < st[-1]:
                # Compare absolute values to determine the outcome of the collision
                if st[-1] < -num:
                    st.pop()  # The positive asteroid is destroyed
                    continue  # Check the next asteroid in the stack for further collisions
                elif st[-1] == -num:
                    st.pop()  # Both asteroids are destroyed
                break  # If the asteroid is not destroyed, exit the loop
            else:
                st.append(num)  # No collision, add the current asteroid to the stack
        return st
