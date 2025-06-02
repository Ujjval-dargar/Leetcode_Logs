class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int a=accumulate(gas.begin(),gas.end(),0);
        int b=accumulate(cost.begin(),cost.end(),0);
        if (b>a) return -1;

        int start=0;
        int total=0;
        for (int i=0;i<n;++i){
            total+=gas[i]-cost[i];
            if (total<0){
                total=0;
                start=i+1;
            }
        }

        return start;
    }
};