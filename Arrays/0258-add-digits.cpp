class Solution {
public:
    int addDigits(int num) {
        int sum = 0, digit;
        while (num != 0) {
            digit = num % 10;
            sum += digit;
            num /= 10;
        }

        if (sum >= 10)
            return addDigits(sum);
        return sum;

    }
};