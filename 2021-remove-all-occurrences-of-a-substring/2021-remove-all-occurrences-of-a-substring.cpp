class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = s;
        auto i = ans.find(part);
        while (i != string::npos){
            ans.erase(i,part.size());
            i = ans.find(part);
        }
        return ans;
    }
};