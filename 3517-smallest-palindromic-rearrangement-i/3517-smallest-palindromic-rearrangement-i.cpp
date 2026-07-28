#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string smallestPalindrome(string s) {
        // Step 1: Count character frequencies
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string first_half = "";
        string middle = "";
        
        // Step 2 & 3: Distribute characters alphabetically
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                char ch = 'a' + i;
                first_half.append(freq[i] / 2, ch);
                
                if (freq[i] % 2 != 0) {
                   middle = ch;
                }
            }
        }
        
        // Step 4: Mirror the prefix
        string total = first_half;
        reverse(first_half.begin(), first_half.end());
        
        return total +middle + first_half;
    }
};
