class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if (n % 2)
            return false;

        stack<int> free;
        stack<int> open;

        for (int i = 0; i < n; ++i) {

            if (locked[i] == '0')
                free.push(i);
            else if (s[i] == '(')
                open.push(i);
            else {
                if (!open.empty())
                    open.pop();
                else {
                    if (!free.empty())
                        free.pop();
                    else
                        return false;
                }
            }
        }

        while (!open.empty() && !free.empty() && open.top() < free.top()) {
            open.pop();
            free.pop();
        }

        cout<<open.size()<<"__"<<free.size()<<endl;
        return open.empty() && free.size() % 2 == 0;
    }
};