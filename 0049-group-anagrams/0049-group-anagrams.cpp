class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;

        for (string &str : strs) {
            int freq[26] = {0};

            for (char c : str)
                freq[c - 'a']++;

            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]);
                key += '#';
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &it : mp)
            ans.push_back(move(it.second));

        return ans;
    }
};