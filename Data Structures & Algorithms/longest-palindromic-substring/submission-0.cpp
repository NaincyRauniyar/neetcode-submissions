class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0, resInd = 0;
        int n = s.size();

        // Odd length
        for(int i = 0; i < n; i++) {
            int l = i, r = i;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    resInd = l;
                }
                l--;
                r++;
            }
        }

        // Even length
        for(int i = 0; i < n; i++) {
            int l = i, r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > resLen) {
                    resLen = r - l + 1;
                    resInd = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(resInd, resLen);
    }
};