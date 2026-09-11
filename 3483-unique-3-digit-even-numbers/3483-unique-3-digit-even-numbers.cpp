class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            freq[a]--;
            freq[b]--;
            freq[c]--;

            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0)
                ans++;

            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return ans;
    }
};