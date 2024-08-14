from collections import defaultdict
import bisect

class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        # Preprocess string s
        char_indices = defaultdict(list)
        for index, char in enumerate(s):
            char_indices[char].append(index)
        
        def is_subsequence(word):
            current_position = -1
            for char in word:
                if char not in char_indices:
                    return False
                # Find the smallest index greater than current_position
                i = bisect.bisect_right(char_indices[char], current_position)
                if i == len(char_indices[char]):
                    return False
                current_position = char_indices[char][i]
            return True
        
        ans = 0
        for word in words:
            if is_subsequence(word):
                ans += 1
        
        return ans
