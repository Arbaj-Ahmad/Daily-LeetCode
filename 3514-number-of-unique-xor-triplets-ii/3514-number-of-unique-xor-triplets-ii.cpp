class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int m = 0;
        for (int v : nums) {
            m = max(m, v);
        }
        int u = 1;
        while (u <= m) {
            u <<= 1;
        }
        vector<int> one(u), two(u), three(u);
        for (int v : nums) {
            one[v] = 1;
            for (int i = 0; i < u; i++) {
                if (one[i]) {
                    two[i ^ v] = 1;
                }
            }
        }
        for (int v : nums) {
            for (int i = 0; i < u; i++) {
                if (two[i]) {
                    three[i ^ v] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < u; i++) {
            if (three[i]) {
                ans++;
            }
        }
        return ans;
    }
};