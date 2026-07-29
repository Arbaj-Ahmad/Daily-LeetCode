class Solution {
public:
    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        long long cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        int mid = -1;
        long long half[26];
        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
            if (cnt[i] % 2 == 1) mid = i;
        }

        int halfLen = n / 2;

        const long long CAP = (long long)4e18; 
        
        
        
        auto countPerms = [&](long long rem[26], long long remLen, long long kLimit) -> long long {
            long long result = 1;
            long long remaining = remLen;
            for (int c = 0; c < 26; c++) {
                long long r = rem[c];
                if (r == 0) continue;
                for (long long i = 1; i <= r; i++) {
                  
                    result = result * (remaining - r + i) / i;
                    if (result > kLimit) return kLimit + 1; // sentinel: big enough
                }
                remaining -= r;
            }
            return result;
        };

        string firstHalf;
        firstHalf.reserve(halfLen);
        long long remLen = halfLen;

        for (int pos = 0; pos < halfLen; pos++) {
            bool placed = false;
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                remLen--;

                long long cntPerms = countPerms(half, remLen, k);

                if (cntPerms >= k) {
                    firstHalf.push_back('a' + c);
                    placed = true;
                    break;
                } else {
                    k -= cntPerms;
                    half[c]++;
                    remLen++;
                }
            }
            if (!placed) return ""; // k too large
        }

        string result = firstHalf;
        if (mid != -1) result.push_back('a' + mid);
        for (int i = firstHalf.size() - 1; i >= 0; i--) result.push_back(firstHalf[i]);

        return result;
    }
};