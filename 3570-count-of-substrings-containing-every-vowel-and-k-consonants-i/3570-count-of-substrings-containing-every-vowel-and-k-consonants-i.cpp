class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int l = 0, r = 0;
        
        // Frequency map for vowels
        unordered_map<char, int> found = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        // Helper map to check if a character is a vowel.
        unordered_map<char, bool> isVowel = {{'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true}};
        
        int cnt_consonant = 0;
        int ans = 0;
        
        while (r < n) {
            char ch = word[r];
            // Update counts depending on whether the character is a vowel.
            if (isVowel.count(ch) && isVowel[ch]) {
                found[ch]++;
            } else {
                cnt_consonant++;
            }
            
            // If the window has too many consonants, shrink it from the left.
            while (l <= r && cnt_consonant > k) {
                char ch_l = word[l];
                if (isVowel.count(ch_l) && isVowel[ch_l]) {
                    found[ch_l]--;
                } else {
                    cnt_consonant--;
                }
                l++;
            }
            
            // When the window has exactly k consonants and contains every vowel at least once...
            if (cnt_consonant == k && found['a'] > 0 && found['e'] > 0 &&
                found['i'] > 0 && found['o'] > 0 && found['u'] > 0) {
                // Use a temporary pointer to count how many starting positions yield a valid window.
                int validStarts = 0;
                int temp = l;
                // Make a copy of the vowel frequency counts.
                auto tempFound = found;
                
                // Try to slide the left boundary as far as possible while still keeping
                // all vowels in the window. We only slide over vowels that occur extra.
                while (temp <= r) {
                    char ch_temp = word[temp];
                    if (isVowel.count(ch_temp) && isVowel[ch_temp]) {
                        if (tempFound[ch_temp] > 1) {
                            tempFound[ch_temp]--;
                            validStarts++;
                            temp++;
                        } else {
                            break;
                        }
                    } else {
                        // Cannot remove a consonant; stop here.
                        break;
                    }
                }
                // The valid starting positions include the original window (when no character is removed)
                // plus each extra removal we could perform.
                ans += (validStarts + 1);
            }
            
            r++;
        }
        
        return ans;
    }
};
