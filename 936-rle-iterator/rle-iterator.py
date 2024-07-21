class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.ind_arr = []
        self.val_arr = []
        self.total_ind = 0
        for i in range(0,len(encoding),2):
            self.total_ind += encoding[i]
            # self.arr.append((total_ind, encoding[i+1]))
            if encoding[i]!=0:
                self.ind_arr.append(self.total_ind)
                self.val_arr.append(encoding[i+1])
        self.last_ind = 0
        

    def next(self, n: int) -> int:
        self.last_ind += n
        ind = bisect_left(self.ind_arr,self.last_ind)
        return -1  if self.last_ind > self.total_ind else self.val_arr[ind]


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)