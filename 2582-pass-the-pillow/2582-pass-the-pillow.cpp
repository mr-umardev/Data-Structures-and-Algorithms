class Solution {
public:
    int passThePillow(int n, int time) {
    int position = 1;
    int direction = 1; // 1 for forward, -1 for backward

    // Simulate passing the pillow for the given time
    for (int t = 0; t < time; ++t) {
        position += direction;
        
        // Change direction if the pillow reaches the first or the last person
        if (position == n) {
            direction = -1;
        } else if (position == 1) {
            direction = 1;
        }
    }

    return position;
}

};