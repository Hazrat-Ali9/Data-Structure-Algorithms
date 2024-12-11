from queue import Queue
class MyStack:

    def __init__(self):
        self.q1 = Queue()
        self.q2 = Queue()

    def push(self, x: int) -> None:
        while not self.q1.empty():
            self.q2.put(self.q1.get())
        self.q1.put(x)
        while not self.q2.empty():
            self.q1.put(self.q2.get())

    def pop(self) -> int:
        return self.q1.get()

    def top(self) -> int:
        return self.q1.queue[0]

    def empty(self) -> bool:
        return self.q1.empty()


# implement stack using Quarry