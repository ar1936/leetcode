from typing import List
from collections import defaultdict

class TrieNode:
    def __init__(self):
        self.is_finish = False
        self.next = defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word: str):
        curr = self.root
        for c in word:
            curr = curr.next[c]
        curr.is_finish = True

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.insert(word)
        
        n = len(board)
        m = len(board[0])
        found_words = set()
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]

        def dfs(x, y, node, word):
            if node.is_finish:
                found_words.add(word)
            
            if x < 0 or x >= n or y < 0 or y >= m or board[x][y] == '#':
                return
            
            char = board[x][y]
            if char not in node.next:
                return
            
            board[x][y] = '#'  # Mark the cell as visited
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                dfs(nx, ny, node.next[char], word + char)
            board[x][y] = char  # Unmark the cell

        for i in range(n):
            for j in range(m):
                if board[i][j] in trie.root.next:
                    dfs(i, j, trie.root, "")
        
        return list(found_words)
