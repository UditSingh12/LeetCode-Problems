class Solution {
public:
    // Using Find() Function
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};