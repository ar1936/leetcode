class Solution:
    def minimumCost(self, s: str, t: str, o: List[str], c: List[str], cost: List[int]) -> int:
        mat = [[10**9]*26 for _ in range(26)]
        for i in range(26):
            mat[i][i] = 0
        for i in range(len(cost)):
            mat[ord(o[i])-97][ord(c[i])-97] = min(mat[ord(o[i])-97][ord(c[i])-97], cost[i])
        
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j])
        
        ans = 0
        for i in range(len(t)):
            st = ord(s[i]) - 97
            tt = ord(t[i]) - 97
            if s[i]!=t[i]:
                if mat[st][tt] == 10**9:
                    return -1
                else:
                    ans+=mat[st][tt]
        return ans