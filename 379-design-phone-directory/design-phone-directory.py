class PhoneDirectory:
    def __init__(self, maxNumbers: int):
        self.size = maxNumbers
        self.mp = set(range(maxNumbers))

    def get(self) -> int:
        if not self.mp:
            return -1
        return self.mp.pop()

    def check(self, number: int) -> bool:
        return number in self.mp

    def release(self, number: int) -> None:
        self.mp.add(number)



# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)