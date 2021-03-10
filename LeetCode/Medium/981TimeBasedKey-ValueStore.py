import bisect


class TimeMap:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dict = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dict[key].append((timestamp, value))
        return

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.dict:
            return ""
        idx = bisect.bisect(self.dict[key], (timestamp, chr(123)))

        if idx:
            return self.dict[key][idx-1][1]
        else:
            return ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
