class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> arr;
        for (int i=1;i<=n;++i){
            arr.push_back(to_string(i));
        }
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for (string i:arr){
            ans.push_back(stoi(i));
        }
        return ans;
    }
};