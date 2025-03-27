class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> arr;

        string temp = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') {
                if (temp != "") {
                    arr.push_back(temp);
                    temp = "";
                }
            } else {
                temp.push_back(s[i]);
            }
        }

        if (temp != "") {
            arr.push_back(temp);
            temp = "";
        }

        n = arr.size();
        string ans="";
        for (int i=n-1;i>=0;--i){
            ans+=arr[i]+" ";
        }

        ans.pop_back();
        return ans;
    }
};