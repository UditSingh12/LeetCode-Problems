class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;

        // First transformation while converting
        for (char c : s) {
            int val = c - 'a' + 1;
            sum += val / 10 + val % 10;
        }

        // Remaining k-1 transformations
        while (--k) {
            int temp = 0;
            while (sum > 0) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }

        return sum;
    }
};