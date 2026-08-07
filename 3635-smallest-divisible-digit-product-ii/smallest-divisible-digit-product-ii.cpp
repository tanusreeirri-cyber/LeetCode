#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    struct Factor {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    Factor getFactors(long long n) {
        Factor f;
        while (n % 2 == 0) { f.c2++; n /= 2; }
        while (n % 3 == 0) { f.c3++; n /= 3; }
        while (n % 5 == 0) { f.c5++; n /= 5; }
        while (n % 7 == 0) { f.c7++; n /= 7; }
        if (n > 1) return {-1, -1, -1, -1};
        return f;
    }

    Factor getDigitFactors(int d) {
        return getFactors(d);
    }

    // Min digits needed to cover c2 factors of 2 and c3 factors of 3
    int minDigits23(int c2, int c3) {
        c2 = max(0, c2);
        c3 = max(0, c3);
        int min_d = 1e9;
        
        for (int n9 = 0; n9 <= c3 / 2; ++n9) {
            for (int n8 = 0; n8 <= c2 / 3; ++n8) {
                int rem3 = c3 - 2 * n9;
                int rem2 = c2 - 3 * n8;
                for (int n6 = 0; n6 <= min(rem2, rem3); ++n6) {
                    int r3 = rem3 - n6;
                    int r2 = rem2 - n6;
                    int n4 = r2 / 2;
                    int r2_left = r2 % 2;
                    
                    int count = n9 + n8 + n6 + n4 + r3 + r2_left;
                    min_d = min(min_d, count);
                }
            }
        }
        return min_d;
    }

    int minDigitsNeeded(Factor f) {
        int c5 = max(0, f.c5);
        int c7 = max(0, f.c7);
        return c5 + c7 + minDigits23(f.c2, f.c3);
    }

    // Builds the lexicographically smallest suffix of length 'len' satisfying factor 'f'
    string buildSuffix(Factor f, int len) {
        int c2 = max(0, f.c2);
        int c3 = max(0, f.c3);
        int c5 = max(0, f.c5);
        int c7 = max(0, f.c7);

        // Find the digit distribution for factors of 2 and 3 that minimizes digit count
        // and produces the smallest string when digits are sorted ascendingly.
        int best_count = 1e9;
        string best_digits23 = "";

        for (int n9 = 0; n9 <= c3 / 2; ++n9) {
            for (int n8 = 0; n8 <= c2 / 3; ++n8) {
                int rem3 = c3 - 2 * n9;
                int rem2 = c2 - 3 * n8;
                for (int n6 = 0; n6 <= min(rem2, rem3); ++n6) {
                    int r3 = rem3 - n6;
                    int r2 = rem2 - n6;
                    int n4 = r2 / 2;
                    int r2_left = r2 % 2;

                    int total = n9 + n8 + n6 + n4 + r3 + r2_left;
                    string s = string(r2_left, '2') + string(r3, '3') + 
                               string(n4, '4') + string(n6, '6') + 
                               string(n8, '8') + string(n9, '9');

                    if (total < best_count || (total == best_count && s < best_digits23)) {
                        best_count = total;
                        best_digits23 = s;
                    }
                }
            }
        }

        string suffix = string(c5, '5') + string(c7, '7') + best_digits23;
        
        while ((int)suffix.length() < len) {
            suffix += '1';
        }

        sort(suffix.begin(), suffix.end());
        return suffix;
    }

public:
    string smallestNumber(string num, long long t) {
        Factor targetFactor = getFactors(t);
        if (targetFactor.c2 == -1) return "-1"; // Prime factor > 7 exists in t

        int n = num.length();

        vector<Factor> pref(n + 1);
        int first_zero = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
            Factor df = getDigitFactors(num[i] - '0');
            pref[i + 1] = {
                pref[i].c2 + df.c2,
                pref[i].c3 + df.c3,
                pref[i].c5 + df.c5,
                pref[i].c7 + df.c7
            };
        }

        // Check if num itself is valid
        if (first_zero == n) {
            Factor remReq = {
                targetFactor.c2 - pref[n].c2,
                targetFactor.c3 - pref[n].c3,
                targetFactor.c5 - pref[n].c5,
                targetFactor.c7 - pref[n].c7
            };
            if (minDigitsNeeded(remReq) <= 0) {
                return num;
            }
        }

        // Try matching prefix of length i (from n-1 down to 0)
        for (int i = min(n - 1, first_zero); i >= 0; i--) {
            Factor curReq = {
                targetFactor.c2 - pref[i].c2,
                targetFactor.c3 - pref[i].c3,
                targetFactor.c5 - pref[i].c5,
                targetFactor.c7 - pref[i].c7
            };

            int start_digit = (num[i] - '0') + 1;
            string best_cand = "";

            for (int d = start_digit; d <= 9; d++) {
                Factor df = getDigitFactors(d);
                Factor remReq = {
                    curReq.c2 - df.c2,
                    curReq.c3 - df.c3,
                    curReq.c5 - df.c5,
                    curReq.c7 - df.c7
                };

                int remLen = n - 1 - i;
                if (minDigitsNeeded(remReq) <= remLen) {
                    string cand = num.substr(0, i) + to_string(d) + buildSuffix(remReq, remLen);
                    if (best_cand.empty() || cand < best_cand) {
                        best_cand = cand;
                    }
                }
            }

            if (!best_cand.empty()) {
                return best_cand;
            }
        }

        // If no number of length n works, expand length
        int targetLen = max(n + 1, minDigitsNeeded(targetFactor));
        return buildSuffix(targetFactor, targetLen);
    }
};