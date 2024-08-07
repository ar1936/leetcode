class Solution:
    def evaluate(self, s: str, k: List[List[str]]) -> str:
        # Create a dictionary for quick look-up of key-value pairs
        replacements = {key: value for key, value in k}
        
        result = []
        n = len(s)
        i = 0
        
        while i < n:
            if s[i] == '(':
                j = i
                while i < n and s[i] != ')':
                    i += 1
                key = s[j+1:i]
                result.append(replacements.get(key, '?'))
            else:
                result.append(s[i])
            i += 1
        
        return ''.join(result)
