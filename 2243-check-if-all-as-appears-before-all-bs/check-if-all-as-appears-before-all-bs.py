class Solution:
    def checkString(self, s: str) -> bool:
        first_a = -1
        first_b = -1
        for i, c in enumerate(s):
            if c=='a':
                # if first_a == -1:
                first_a = i
            if c=='b':
                if first_b == -1:
                    first_b = i
        if first_b == -1:
            return True
        return first_a<first_b