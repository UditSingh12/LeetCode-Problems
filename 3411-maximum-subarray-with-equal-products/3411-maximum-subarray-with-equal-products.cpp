
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int primeSum[4] = {0};
            int primeMax[4] = {0};
            int primeMin[4] = {0};

            for (int j = i; j < n; j++) {
                int x = nums[j];
                int factors[4] = {0};
                int primes[4] = {2, 3, 5, 7};

                for (int k = 0; k < 4; k++) {
                    while (x % primes[k] == 0) {
                        factors[k]++;
                        x /= primes[k];
                    }
                }

                for (int k = 0; k < 4; k++) {
                    primeSum[k] += factors[k];

                    if (j == i) {
                        primeMax[k] = factors[k];
                        primeMin[k] = factors[k];
                    } else {
                        primeMax[k] = max(primeMax[k], factors[k]);
                        primeMin[k] = min(primeMin[k], factors[k]);
                    }
                }

                bool valid = true;

                for (int k = 0; k < 4; k++) {
                    if (primeSum[k] != primeMax[k] + primeMin[k]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
