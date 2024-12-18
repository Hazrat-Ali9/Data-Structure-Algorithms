class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Returns false if the new booking overlaps with the existing
        // double-booked bookings.
        for (pair<int, int> booking : overlapBookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                return false;
            }
        }

        // Add the double overlapping if any with the new booking.
        for (pair<int, int> booking : bookings) {
            if (doesOverlap(booking.first, booking.second, start, end)) {
                overlapBookings.push_back(
                    getOverlapped(booking.first, booking.second, start, end));
            }
        }

        // Add the booking to the list of bookings.
        bookings.push_back({start, end});
        return true;
    }

private:
    // Return true if the booking [start1, end1) & [start2, end2) overlaps.
    bool doesOverlap(int start1, int end1, int start2, int end2) {
        return max(start1, start2) < min(end1, end2);
    }

    // Return overlapping booking between [start1, end1) & [start2, end2).
    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
};