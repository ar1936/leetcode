class Solution:
    def removeStars(self, s: str) -> str:
        st = ""
        for c in s:
            if len(st) and c=='*':
                st = st[:-1]
            else :
                st+=c
        return st