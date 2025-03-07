class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = 1e6 + 1;
        vector<int> prime(n, true);
        prime[1]=false;
        for (int i = 2; i * i < n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int num1=-1;
        int num2=-1;

        for (int i=left;i<=right;++i){
            if (prime[i]){
                for (int j=i+1;j<=right;++j){
                    if (prime[j]){
                        int t = j-i;
                        if ((num1==-1 && num2==-1)||t<num2-num1){
                            cout<<i<<" "<<j<<endl;
                            num1=i;
                            num2=j;
                            i=j-1;
                            break;
                        }
                        else {
                            i=j-1;
                            break;
                        }
                    }
                }
            }
            
        }
        return {num1, num2};
    }
};