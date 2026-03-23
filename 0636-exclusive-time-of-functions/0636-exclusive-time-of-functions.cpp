class Solution {
public:

    vector<string> split(string s){
        vector<string> ans;
        string curr = "";
        for (char ch : s){
            if (ch == ':'){
                ans.push_back(curr);
                curr = "";
            }
            else {
                curr.push_back(ch);
            }
        }

        if (curr!=""){
            ans.push_back(curr);
        }

        return ans;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<vector<int>> stk;

        for (string s : logs){
            vector<string> ss = split(s);
            int f = stoi(ss[0]);
            string op = ss[1];
            int t = stoi(ss[2]);

            if (op == "start"){
                if (stk.empty()){
                    stk.push({f,t,0});
                }
                else {
                    vector<int> tp = stk.top(); stk.pop();
                    tp[2] += t - tp[1];

                    stk.push(tp);
                    stk.push({f,t,0});
                }
            }
            else {
                vector<int> tp = stk.top(); stk.pop();
                tp[2] += t - tp[1] + 1;
                
                ans[f] += tp[2];

                if (!stk.empty()){
                    vector<int> tp = stk.top(); stk.pop();
                    tp[1] = t + 1;

                    stk.push(tp);
                }
            }
        }

        return ans;
    }
};