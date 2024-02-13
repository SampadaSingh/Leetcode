class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return -dividend;

        bool isMin = false;
        if (dividend == INT_MIN) {
            isMin = true;
            dividend++;
        }
        int result = 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long dividendAbs = labs(dividend);
        long divisorAbs = labs(divisor);
        while (dividendAbs >= divisorAbs) {
            long temp = divisorAbs, k = 1;
            while (temp << 1 > 0 && temp << 1 <= dividendAbs) {
                temp <<= 1;
                k <<= 1;
            }
            dividendAbs -= temp;
            if (result < INT_MAX - k) {
                result += k;
            } else {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        if (isMin) {
            dividendAbs++;
            while (dividendAbs >= divisorAbs) {
                if (result == INT_MAX)
                    return INT_MAX;
                result++;
                dividendAbs -= divisorAbs;
            }
        }
        return sign == 1 ? result : -result;
    }
};
