class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int total_moves = 0;
    for (size_t i = 0; i < seats.size(); ++i) {
        total_moves += abs(students[i] - seats[i]);
}

    return total_moves;
    }
};



