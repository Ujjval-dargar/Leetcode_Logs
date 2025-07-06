struct coupon {
    string code;
    string business;
    bool active;

    coupon(string c, string bus, bool act) {
        code = c;
        business = bus;
        active = act;
    }
};

class Solution {
public:
    bool isValid(coupon* c) {
        string business = c->business;
        if (business != "electronics" && business != "grocery" &&
            business != "pharmacy" && business != "restaurant") {
            return false;
        }

        string code = c->code;
        if (code == "") return false;

        for (char ch : code) {
            if (!isdigit(ch) && !isalpha(ch) && ch != '_') {
                return false;
            }
        }

        return c->active;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<coupon*> arr;
        for (int i = 0; i < n; ++i) {
            coupon* c = new coupon(code[i], businessLine[i], isActive[i]);
            if (isValid(c))
                arr.push_back(c);
        }

        sort(arr.begin(), arr.end(), [](const coupon* a, const coupon* b) {
            if (a->business != b->business) {
                return a->business < b->business;
            }

            return a->code < b->code;
        });

        vector<string> ans;
        for (auto c : arr) {
            ans.push_back(c->code);
        }

        return ans;
    }
};