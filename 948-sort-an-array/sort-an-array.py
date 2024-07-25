class Solution:
    # selection sort
    # def sortArray(self, nums: List[int]) -> List[int]:
    #     # selection sort
    #     for i in range(len(nums)):
    #         min_ind = i
    #         for j in range(i,len(nums)):
    #             if(nums[min_ind]>nums[j]):
    #                 min_ind = j
    #         nums[i], nums[min_ind] = nums[min_ind], nums[i]
    #     return nums


    # def sortArray(self, nums: List[int]) -> List[int]:
    #     n = len(nums)
    #     for i in range(n):
    #         for j in range(n-i-1):
    #             if nums[j]>nums[j+1]:
    #                 nums[j], nums[j+1] = nums[j+1], nums[j]
    #     return nums

    def mergeSort(self,arr:list):
        if len(arr)>1:
            mid = len(arr)//2
            L = arr[:mid]
            R = arr[mid:]
            self.mergeSort(L)
            self.mergeSort(R)
            i=j=k=0
            while i<len(L) and j<len(R):
                if L[i]<R[j]:
                    arr[k] = L[i]
                    i+=1
                else:
                    arr[k] = R[j]
                    j+=1
                k+=1
            while i<len(L):
                arr[k] = L[i]
                i+=1
                k+=1

            while j<len(R):
                arr[k] = R[j]
                j+=1
                k+=1
             
    def sortArray(self, nums: List[int]) -> List[int]:
        self.mergeSort(nums)
        return nums