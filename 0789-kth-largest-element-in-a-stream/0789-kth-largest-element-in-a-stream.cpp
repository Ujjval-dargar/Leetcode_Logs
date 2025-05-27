class KthLargest {
public:
    multiset<int> st;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        st.insert(nums.begin(), nums.end());
    }

    int add(int val) {
        st.insert(val);
        auto it = st.end();
        for (int i = 0; i < k; ++i) {
            --it;
        }
        return *it;
    }
};
