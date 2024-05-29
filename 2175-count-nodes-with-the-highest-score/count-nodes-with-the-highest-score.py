class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        # Create a dictionary to store children for each parent
        children = defaultdict(list)
        for child, parent in enumerate(parents):
            if parent != -1:
                children[parent].append(child)
        
        # Function to calculate the size of each subtree
        def calculate_size(node):
            size = 1  # Initialize size with 1 to include the current node
            for child in children[node]:
                size += calculate_size(child)  # Add the size of each child subtree
            subtree_size[node] = size
            return size
        
        # Dictionary to store the size of each subtree
        subtree_size = [0] * len(parents)
        calculate_size(0)  # Calculate the size of all subtrees starting from the root
        
        # Dictionary to store the scores
        scores = defaultdict(int)
        max_score = 0
        
        # Function to calculate the score of each node
        def calculate_score(node):
            nonlocal max_score
            score = 1
            total_nodes = len(parents)
            
            # Calculate the product of sizes of subtrees after removing the current node
            for child in children[node]:
                score *= subtree_size[child]
            
            # If the current node is not the root, include the size of the "remaining" subtree
            if node != 0:
                score *= (total_nodes - subtree_size[node])
            
            # Update the maximum score and the count of nodes with that score
            max_score = max(max_score, score)
            scores[score] += 1
        
        # Calculate the score for each node
        for node in range(len(parents)):
            calculate_score(node)
        
        # Return the number of nodes with the highest score
        return scores[max_score]