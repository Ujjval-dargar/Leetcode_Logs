class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        int cntA = 0;
        int cntB = 0;

        vector<int> ans;

        for (char ch : seq){
            if (ch == '('){
                if (cntA < cntB) {cntA++; ans.push_back(0);}
                else {cntB++; ans.push_back(1);}
            }
            else {
                if (cntA > 0 && cntB > 0){
                    if (cntA > cntB) {cntA--; ans.push_back(0);}
                    else {cntB--; ans.push_back(1);}
                }
                else if (cntA > 0) {cntA--; ans.push_back(0);}
                else {cntB--; ans.push_back(1);}
            }
        }

        return ans;
    }
};