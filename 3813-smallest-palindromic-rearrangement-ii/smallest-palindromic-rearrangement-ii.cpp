class Solution {
public:
    static const long long CAP = 1000001; // > max possible k (1e6)

    long long combCapped(long long a, long long b) {
        if (b < 0 || b > a) return 0;
        b = min(b, a - b);
        long long res = 1;
        for (long long i = 1; i <= b; i++) {
            res = res * (a - b + i) / i;
            if (res >= CAP) return CAP;
        }
        return res;
    }

    long long permCountCapped(vector<int>& counts, int total) {
        long long result = 1;
        int remaining = total;
        for (int c = 0; c < 26; c++) {
            if (counts[c] == 0) continue;
            long long cval = combCapped(remaining, counts[c]);
            result *= cval;
            remaining -= counts[c];
            if (result >= CAP) return CAP;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {   // <-- renamed to match LeetCode's expected signature
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        vector<int> half(26, 0);
        int midChar = -1;
        for (int c = 0; c < 26; c++) {
            half[c] = cnt[c] / 2;
            if (cnt[c] % 2 == 1) midChar = c;
        }

        int halfLen = n / 2;
        long long kk = k;

        long long total = permCountCapped(half, halfLen);
        if (kk > total) return "";

        string leftHalf;
        leftHalf.reserve(halfLen);
        vector<int> remCounts = half;
        int remLen = halfLen;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (remCounts[c] == 0) continue;
                remCounts[c]--;
                long long cnt2 = permCountCapped(remCounts, remLen - 1);
                if (kk <= cnt2) {
                    leftHalf.push_back('a' + c);
                    remLen--;
                    break;
                } else {
                    kk -= cnt2;
                    remCounts[c]++;
                }
            }
        }

        string result = leftHalf;
        if (midChar != -1) result.push_back('a' + midChar);
        for (int i = (int)leftHalf.size() - 1; i >= 0; i--) result.push_back(leftHalf[i]);

        return result;
    }
};