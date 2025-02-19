class Solution {
public:
    string helper(int l, int r, int k, int n, int curr, string lst) {
        if (curr == n)
            return "";

        if (lst == "") {

            if (k <= r / 3) {
                return "a" + helper(0, r / 3, k, n, curr + 1, "a");
            } else if (k <= 2 * r / 3) {
                return "b" + helper(r / 3 + 1, 2 * r / 3, k, n, curr + 1, "b");
            } else {
                return "c" + helper(2 * r / 3 + 1, 3 * r / 3,k, n, curr + 1, "c");
            }
        } else {
            int mid = (l + r) / 2;

            if (l <= k && k <= mid) {
                if (lst == "a")
                    return "b" + helper(l, mid, k, n, curr + 1, "b");
                else if (lst == "b")
                    return "a" + helper(l, mid, k, n, curr + 1, "a");
                else if (lst == "c")
                    return "a" + helper(l, mid, k, n, curr + 1, "a");
            } else {
                if (lst == "a")
                    return "c" + helper(mid + 1, r, k, n, curr + 1, "c");
                else if (lst == "b")
                    return "c" + helper(mid + 1, r, k, n, curr + 1, "c");
                else if (lst == "c")
                    return "b" + helper(mid + 1, r, k, n, curr + 1, "b");
            }
        }

        return "";
    }

    string getHappyString(int n, int k) {

        int m = 3 * pow(2, n - 1);

        if (k <= m) {
            return helper(0, m, k, n, 0, "");
        }

        return "";
    }
};