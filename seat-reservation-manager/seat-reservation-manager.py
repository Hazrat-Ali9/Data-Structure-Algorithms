class SeatManager:

    def __init__(self, n: int):
        self.pq = [i for i in range(1, n+1)]

    def reserve(self) -> int:
        seatNumber = heapq.heappop(self.pq)
        return seatNumber

    def unreserve(self, seatNumber: int) -> None:
        heapq.heappush(self.pq, seatNumber)


# Seat Reservation manager