class TrieNode:
    def __init__(self):
        self.is_finish = False
        self.next = defaultdict(TrieNode)
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self,word):
        node = self.root
        for c in word:
            node = node.next[c]
        node.is_finish = True
    def is_valid_word(self,word):
        node = self.root
        for c in word:
            node = node.next[c]
            if node.is_finish == False:
                return False
        return True
class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        for word in words:
            trie.insert(word)
        ans = ""
        for word in words:
            if trie.is_valid_word(word):
                if len(ans)<len(word):
                    ans = word
                if len(ans) == len(word) and ans>word:
                    ans = word
        return ans