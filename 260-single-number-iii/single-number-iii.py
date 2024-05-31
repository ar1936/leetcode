class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        all_xor = nums[0]
        for i in range(1,len(nums)):
            all_xor^=nums[i]
        binary_all_xor = []
        all_xor = abs(all_xor)
        while all_xor:
            # print(all_xor)
            binary_all_xor.append(all_xor%2)
            all_xor = all_xor//2
        binary_all_xor = binary_all_xor[::-1]
        # print(binary_all_xor)
        first_bit_ind = len(binary_all_xor)-1
        # print(first_bit_ind)
        while binary_all_xor[first_bit_ind]!=1:
            first_bit_ind-=1
        first_bit_ind = len(binary_all_xor) - first_bit_ind-1
        # print(first_bit_ind)
        num1 = 0
        num2 = 0
        for num in nums:
            ind_tmp = first_bit_ind
            num_tmp = num
            while ind_tmp:
                num_tmp = num_tmp//2
                ind_tmp-=1
            if num_tmp%2==0:
                # print(1,num)
                num1^=num
            else:
                # print(2,num)
                num2^=num
        return [num1,num2]