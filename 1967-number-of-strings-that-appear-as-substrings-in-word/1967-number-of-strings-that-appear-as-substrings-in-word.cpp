class Solution {
public:
     bool isSubstring(string word, string pattern) {

        int n = word.size();
        int m = pattern.size();

        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            while (j < m && word[i + j] == pattern[j]) {
                j++;
            }

            if (j == m)
                return true;
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string pattern : patterns) {
            if (isSubstring(word, pattern))
                count++;
        }

        return count;
    }
};