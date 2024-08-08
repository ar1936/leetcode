class TrieNode:
    def __init__(self):
        self.is_finish = False
        self.next = defaultdict(TrieNode)
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self,word):
        node = self.root
        arr = word.split('/')
        for c in arr:
            node = node.next[c]
        node.is_finish = True

    def is_valid(self,word):
        node = self.root
        arr = word.split('/')
        for c in arr:
            if node.is_finish:
                return False
            node = node.next[c]
        return True

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        trie = Trie()
        for f in folder:
            trie.insert(f)
        ans = []
        for f in folder:
            if trie.is_valid(f):
                ans.append(f)
        return ans