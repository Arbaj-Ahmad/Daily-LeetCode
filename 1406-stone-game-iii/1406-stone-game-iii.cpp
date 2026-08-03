class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4] = {0, 0, 0, 0};  // rolling array, dp[i % 4]
        
        for (int i = n - 1; i >= 0; i--) {
            int best = INT_MIN;
            int total = 0;
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                total += stoneValue[i + k - 1];
                best = max(best, total - dp[(i + k) % 4]);
            }
            dp[i % 4] = best;
        }
        
        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};