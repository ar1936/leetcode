class TrieNode:
    def __init__(self):
        self.is_finish = False
        self.next = defaultdict(TrieNode)
        
class WordDictionary:

    def __init__(self):
        self.root = TrieNode()
        self.mp = defaultdict(set) # this will help us to store char at specific index
            
    def addWord(self, word: str) -> None:
        curr = self.root
        for ind,c in enumerate(word):
            curr = curr.next[c]
            self.mp[ind].add(c)
        curr.is_finish = True


    def search(self, word: str) -> bool:
        def dfs(node, index):
            if index == len(word):
                return node.is_finish
            if word[index] == '.':
                for child in node.next.values():
                    if dfs(child, index + 1):
                        return True
            else:
                if word[index] in node.next:
                    return dfs(node.next[word[index]], index + 1)
            return False

        return dfs(self.root, 0)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)