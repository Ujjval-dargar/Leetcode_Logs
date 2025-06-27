class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> nextRow(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                nextRow[j] = row[j - 1] + row[j];
            }
            row = nextRow;
        }

        return row;
    }
};