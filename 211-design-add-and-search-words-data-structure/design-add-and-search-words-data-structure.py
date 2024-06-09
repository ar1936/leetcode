class WordDictionary:

    def __init__(self):
        self.mp = defaultdict(int)
    def addWord(self, word: str) -> None:
        self.mp[word] += 1

    def search(self, word: str) -> bool:
        count_dot = 0
        dot_ind = []
        if word in self.mp:
            return True
        for ind, s in enumerate(word):
            if s == '.':
                count_dot += 1
                dot_ind.append(ind)
        
        if count_dot == 1:
            for i in range(26):
                temp_word = list(word)
                temp_word[dot_ind[0]] = chr(i + 97)
                new_word = ''.join(temp_word)
                if new_word in self.mp:
                    return True
        
        if count_dot == 2:
            for i in range(26):
                for j in range(26):
                    temp_word = list(word)
                    temp_word[dot_ind[0]] = chr(i + 97)
                    temp_word[dot_ind[1]] = chr(j + 97)
                    new_word = ''.join(temp_word)
                    if new_word in self.mp:
                        return True
        
        return False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)