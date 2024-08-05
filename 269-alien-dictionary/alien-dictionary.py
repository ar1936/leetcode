class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = defaultdict(list)
        indegree = defaultdict(int)
        n = len(words)
        all_char = set()
        for word in words:
            for c in word:
                all_char.add(c)
                
        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            min_len = min(len(w1), len(w2))
            if w1[:min_len] == w2[:min_len] and len(w1) > len(w2):
                return ""  # Edge case: if one word is prefix of the other but comes after
            for c1, c2 in zip(w1, w2):
                if c1 != c2:
                    if c2 not in graph[c1]:
                        graph[c1].append(c2)
                        indegree[c2] += 1
                    break
        q = deque()
        for key in all_char:
            if indegree[key] == 0:
                q.append(key)
        
        ans = ""
        while q:
            prev_char = q.popleft()
            ans+=prev_char
            for next_char in graph[prev_char]:
                indegree[next_char] -= 1
                if indegree[next_char] == 0:
                    q.append(next_char)
        if len(ans)!=len(graph):
            return ""
        return ans