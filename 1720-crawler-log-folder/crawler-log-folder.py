class Solution:
    def minOperations(self, logs: List[str]) -> int:
        mn = 0 
        for log in logs:
            if log == '../':
                mn -= 1
            elif log !=  './':
                mn += 1
            if mn<0:
                mn = 0
        return mn