class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        left = 0
        right = len(products) - 1
        ans = []

        for i in range(len(searchWord)):
            # Move `left` to the first product that matches the current prefix
            while left <= right and (len(products[left]) <= i or products[left][i] < searchWord[i]):
                left += 1
            
            # Move `right` to the last product that matches the current prefix
            while right >= left and (len(products[right]) <= i or products[right][i] > searchWord[i]):
                right -= 1
            
            # Append the results for this prefix directly to `ans`
            ans.append([products[left + j] for j in range(min(3, right - left + 1))])
        
        return ans
