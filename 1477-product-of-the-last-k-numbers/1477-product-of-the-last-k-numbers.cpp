class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {}

    void add(int num) {
        int n = nums.size();

        if (n == 0) {
            nums.push_back(num);
        } else {
            nums.push_back(num * nums[n - 1]);
        }

        if (num == 0) {
            nums.clear();
        }
    }

    int getProduct(int k) {
        int n = nums.size();

        if (n-1-k>=0)
            return nums[n - 1] / nums[n - 1 - k];
        else if (n-1-k==-1)
            return nums[n-1];
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */