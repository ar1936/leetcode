class TrieNode:
    def __init__(self):
        self.next = defaultdict(TrieNode)
        self.val = 0
        
class MapSum:

    def __init__(self):
        self.root = TrieNode()
        self.mp = defaultdict(int)

    def insert(self, key: str, val: int) -> None:
        delta = val - self.mp[key] 
        self.mp[key] = val
        curr = self.root
        curr.val += delta 
        for c in key:
            if c not in curr.next:
                curr.next[c] = TrieNode()
            curr = curr.next[c]
            curr.val += delta
        
    def sum(self, prefix: str) -> int:
        curr = self.root
        for s in prefix:
            if s not in curr.next:
                return 0
            curr = curr.next[s]
        return curr.val 


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)