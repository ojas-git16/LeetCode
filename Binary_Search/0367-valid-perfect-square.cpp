class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 0; pow(i, 2) <= num; i++) {
            if (i * i == num)
                return 1;
        }
        return 0;
    }
};