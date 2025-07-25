class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for (string &s:strs){
            string key = s;
            sort(key.begin(),key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &i:mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};