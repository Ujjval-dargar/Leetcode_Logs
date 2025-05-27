class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize)
            return false;

        sort(hand.begin(),hand.end());

        for (int i:hand){
            cout<<i<<" ";
        }
        cout<<endl;

        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            int cnt = 1;
            visited[i] = true;
            int ele = hand[i];
            int j = i + 1;
            while (j < n && cnt < groupSize) {
                if (hand[j] - ele == 1 && !visited[j]) {
                    ele = hand[j];
                    visited[j] = true;
                    cnt++;
                }
                j++;
            }

            // cout << cnt << "__" << i << endl;
            // for (bool k : visited)
            //     cout << k << " ";
            // cout << endl;

            if (cnt != groupSize) {
                return false;
            }
        }

        return true;
    }
};