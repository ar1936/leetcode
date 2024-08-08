from collections import defaultdict
from typing import List

class TrieNode:
    def __init__(self):
        self.is_finish = False
        self.next = defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word: str):
        node = self.root
        for c in word:
            node = node.next[c]
        node.is_finish = True
    
    def is_valid_word(self, word: str) -> bool:
        node = self.root
        for c in word:
            node = node.next[c]
            if not node.is_finish:
                return False
        return True

class Solution:
    def longestWord(self, words: List[str]) -> str:
        trie = Trie()
        for word in words:
            trie.insert(word)
        
        longest_word = ""
        for word in words:
            if trie.is_valid_word(word):
                if len(word) > len(longest_word):
                    longest_word = word
                elif len(word) == len(longest_word) and word < longest_word:
                    longest_word = word
        
        return longest_word
