
#include <string>
using namespace std;

class Solution {
public:
    bool check(string &s, int l, int r, int used) {
        if (l >= r) {
            return true;
        }

        if (s[l] == s[r]) {
            return check(s, l + 1, r - 1, used);
        }

        if (used == 1) {
            return false;
        }

        return check(s, l + 1, r, 1) || check(s, l, r - 1, 1);
    }

    bool validPalindrome(string s) {
        return check(s, 0, s.size() - 1, 0);
    }
};
/**
 Reminder: Use Recursion
 */