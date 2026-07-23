

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        
        int msb = 31 - __builtin_clz(n);
        return 1 << (msb + 1);
    }
};