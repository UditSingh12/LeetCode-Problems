class Solution {
public:

    //Using Bucket Sort 
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        vector<string> bucket(s.size() + 1);

        for (auto &it : freq) {
            bucket[it.second] += it.first;
        }

        string ans;

        for (int i = s.size(); i >= 1; i--) {
            for (char c : bucket[i]) {
                ans += string(i, c);
            }
        }

        return ans;
    }
};