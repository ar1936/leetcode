class Logger:

    def __init__(self):
        self.mp = defaultdict(str)

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        if message in self.mp:
            if (timestamp - self.mp[message]) >= 10:
                self.mp[message] = timestamp
                return True
            else:
                return False
        else:
            self.mp[message] = timestamp
            return True


# Your Logger object will be instantiated and called as such:
# obj = Logger()
# param_1 = obj.shouldPrintMessage(timestamp,message)