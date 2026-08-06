class Solution {
public:
    int helper(int num) {
        int output = 1;
        while (num > 0) {
            output *= (num % 10);
            num /= 10;
        }
        return output;
    }

    int smallestNumber(int n, int t) {
         while (true) {
            int output = helper(n);
            if (output % t == 0){
                return n;
            }
            n++;
        }
    }
};