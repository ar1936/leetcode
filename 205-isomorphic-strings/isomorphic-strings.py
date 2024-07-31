class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp = defaultdict()
        m = defaultdict()
        for a,b in zip(s,t):
            if a in mp:
                if b!=mp[a]:
                    return False
            if b in m:
                if a!=m[b]:
                    return False
            m[b] = a
            mp[a] = b
        return True