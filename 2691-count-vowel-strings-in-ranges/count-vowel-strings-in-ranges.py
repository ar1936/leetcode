class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        arr = [0]
        for w in words:
            if w[0] in ['a','e','i','o','u'] and w[-1] in ['a','e','i','o','u']:
                arr.append(1)
            else:
                arr.append(0)
            arr[-1] += arr[-2]
        ans = []
        for q1,q2 in queries:
            ans.append(arr[q2+1]-arr[q1])
        return ans