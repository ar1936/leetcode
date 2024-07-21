class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], target: List[str]) -> str:
        ans = s
        arr = []
        for i in range(len(indices)):
            arr.append([indices[i], sources[i], target[i]])
        arr.sort(key=lambda x:x[0], reverse= True)
        for ind, sc, tar in arr:
            if s[ind:ind+len(sc)] == sc:
                ans = ans[:ind] + tar + ans[ind+len(sc):]
        return ans