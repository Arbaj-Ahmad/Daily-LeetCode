class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int len = s.size();
        int d1 = s[len - 1] - '0';
        int d2 = s[len - 2] - '0';
        return d1 * d2;
    }
};