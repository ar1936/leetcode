# class Solution:
#     def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
#         adj = {}
#         prob = {}
#         for ind, edge in enumerate(edges):
#             adj.setdefault(edge[0], []).append((edge[1],succProb[ind]))
#             prob.setdefault(edge[0],-1)
#             if edge[1] in adj:
#                 adj[edge[1]].append((edge[0],succProb[ind]))
#             else:
#                 adj.setdefault(edge[1], []).append((edge[0],succProb[ind]))
#                 prob.setdefault(edge[1],-1)
#         prob.setdefault(end_node,-1)
#         print(prob)
#         heap = []
#         prob[start_node] = 1
#         heap.append((1,start_node))
#         heapq.heapify(heap)
#         vis = set()
#         vis.add(start_node)
#         while heap:
#             prev_prob, prev_node = heapq.heappop(heap)
#             if prev_node in adj:
#                 for curr_node,curr_prob in adj[prev_node]:
#                     total_prob = prev_prob*curr_prob
#                     if curr_node not in vis and  total_prob>prob[curr_node]:
#                         heapq.heappush(heap,(total_prob,curr_node))
#                         prob[curr_node] = total_prob
#                         vis.add(curr_node)
#         return prob[end_node] if prob[end_node] != -1 else 0




class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start_node: int, end_node: int) -> float:
        adj = {}
        prob = {}
        for ind, edge in enumerate(edges):
            # Simplified the adjacency list creation by removing the if-else check
            adj.setdefault(edge[0], []).append((edge[1], succProb[ind]))
            prob.setdefault(edge[0], 0)  # Initialize probabilities with 0 instead of -1
            adj.setdefault(edge[1], []).append((edge[0], succProb[ind]))
            prob.setdefault(edge[1], 0)  # Initialize probabilities with 0 instead of -1
        prob[end_node] = 0  # Ensure the end node is in the prob dictionary
        
        # Initialize the heap with a tuple containing negative probability and start node
        heap = [(-1, start_node)]  # Negative probability for max heap
        prob[start_node] = 1  # Start node has probability 1
        vis = set()  # Set to keep track of visited nodes
        
        while heap:
            # Pop from heap and convert back to positive probability
            prev_prob, prev_node = heapq.heappop(heap)
            prev_prob = -prev_prob  # Convert back to positive probability
            if prev_node == end_node:
                return prev_prob  # Return the probability if end node is reached
            
            # Check if the node has been visited before processing
            if prev_node in vis:
                continue
            vis.add(prev_node)  # Mark the node as visited
            
            # Iterate over neighbors
            for curr_node, curr_prob in adj.get(prev_node, []):
                total_prob = prev_prob * curr_prob
                # Check if the new probability is greater and the node has not been visited
                if curr_node not in vis and total_prob > prob[curr_node]:
                    heapq.heappush(heap, (-total_prob, curr_node))  # Push negative probability
                    prob[curr_node] = total_prob  # Update the probability
        
        return prob[end_node]  # Return the probability for the end node, or 0 if not reachable