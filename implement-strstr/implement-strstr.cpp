#define ll int
class Solution {
public:
    // 1 indexed .. p[i] is the length of the longest proper prefix of the substring s[0 … i - 1] which is also a suffix of this substring
    vector<int> LPS(string &s) {
        int n = (int)s.length();
        vector<ll> p(n + 1);
        p[0] = 0; p[1] = 0;
        int j;
        for (int i = 2 ; i <= n ; i++) {
            j = p[i - 1];
            while (j > 0 && s[j] != s[i - 1]) j = p[j]; // p[p[j]] gives second largest prefix of the substring s[0 … i - 1]
            if (s[j] == s[i - 1]) j++;
            p[i] = j;
        }
        return p;
    }
    int strStr(string s, string t) {
        if(t == "") return 0;
        string x = t + '$' + s;
        vector<int> v = LPS(x);

        int len = (int)t.length();
        for (int i = len; i <= (int)x.size(); i++) {
            if (v[i] == len) {
                return i - len - len  - 1;
            }
        }

        return -1;
    }
};