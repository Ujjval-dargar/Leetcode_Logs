class NumberContainers {
public:
    unordered_map<int, int> mp;
    unordered_map<int, set<int>> m;

    NumberContainers() {}

    void change(int index, int number) {
        int prev = mp[index];

        if (prev != 0) {
            m[prev].erase(index);
        }

        mp[index] = number;
        m[number].insert(index);
    }

    int find(int number) {
        if (m[number].size() > 0) {
            return *m[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */