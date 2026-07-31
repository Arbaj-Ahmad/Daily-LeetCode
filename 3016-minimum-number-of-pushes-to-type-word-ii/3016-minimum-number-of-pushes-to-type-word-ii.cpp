#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumPushes(std::string word) {
        // Step 1: Count frequencies of each character
        std::vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Step 2: Sort frequencies in descending order
        std::sort(freq.begin(), freq.end(), std::greater<int>());
        
        // Step 3: Greedily calculate the total minimum pushes
        int total_pushes = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) {
                break; // No more characters left to map
            }
            
            // Map cost brackets: indices 0-7 cost 1, 8-15 cost 2, etc.
            int push_cost = (i / 8) + 1;
            total_pushes += freq[i] * push_cost;
        }
        
        return total_pushes;
    }
};


    