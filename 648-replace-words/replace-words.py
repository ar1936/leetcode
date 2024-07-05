class TrieNode:
    def __init__(self):
        self.next = defaultdict(TrieNode)
        self.is_finish = False

class Solution:
    def __init__(self):
            self.root = TrieNode()

    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        def insert(word):
            curr = self.root 
            for c in word:
                curr = curr.next[c]
            curr.is_finish = True

        def replace(word):
            curr = self.root
            match = "" 
            for c in word:
                if c in curr.next:
                    match += c
                curr = curr.next[c]
                if curr.is_finish == True:
                    return match 
            return ""

        for d in dictionary:
            insert(d)
        
        ans = ""
        sentence = sentence.split()

        for s in sentence:
            replace_word = replace(s)
            if replace_word != "":
                ans += replace_word
            else:
                ans+= s
            ans+=' '
        return ans[:-1]