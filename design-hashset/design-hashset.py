class MyHashSet:
    def __init__(self):
        self.s = [0]*(10**6 + 1)
        
    def add(self, key: int) -> None:
        self.s[key] = 1

    def remove(self, key: int) -> None:
        self.s[key] = 0

    def contains(self, key: int) -> bool:
        return self.s[key] == 1


# design hashset