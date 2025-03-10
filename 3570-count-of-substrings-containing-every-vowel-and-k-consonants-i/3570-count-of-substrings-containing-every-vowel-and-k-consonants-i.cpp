;
class Solution {
public:
    int countOfSubstrings(string word, int k) {

        int n = word.size();

        int l = 0;
        int r = 0;

        unordered_map<char, int> found;
        found['a'] = 0;
        found['e'] = 0;
        found['i'] = 0;
        found['o'] = 0;
        found['u'] = 0;

        unordered_map<char, bool> vowels;
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;

        int cnt_consonant = 0;

        int ans = 0;

        while (r < n) {

            char ch = word[r];

            if (vowels[ch]) {
                found[ch]++;
            } else {
                cnt_consonant++;
            }

            while (l<=r && cnt_consonant > k) {
                char ch_l = word[l];

                if (vowels[ch_l]) {
                    found[ch_l]--;
                } else {
                    cnt_consonant--;
                }
                l++;
            }

            if (cnt_consonant == k && found['a'] > 0 && found['e'] > 0 &&
                found['i'] > 0 && found['o'] > 0 && found['u'] > 0) {
                int valid_l = 0;
                int temp = l;
                unordered_map<char, int> tempFound = found;

                while (temp<r){
                    char ch_temp = word[temp];
                    if (vowels[ch_temp]) {

                        if (tempFound[ch_temp]>1){
                            tempFound[ch_temp]--;
                            valid_l++;
                            temp++;
                        }else {
                            break;
                        }
                        
                    } else {
                        break;
                    }
                }

                ans += valid_l+1;

            }

            r++;
        }

        return ans;
    }
};