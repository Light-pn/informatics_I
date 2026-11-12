
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> freq(1000001, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, distinct = 0;
    int best = 0, ansL = 0, ansR = 0;

    for (int r = 0; r < n; r++) {
        if (freq[a[r]] == 0) {
            distinct++;
        }

        freq[a[r]]++;

        while (distinct > k) {
            freq[a[l]]--;

            if (freq[a[l]] == 0) {
                distinct--;
            }

            l++;
        }

        if (r - l + 1 > best) {
            best = r - l + 1;
            ansL = l;
            ansR = r;
        }
    }

    cout << ansL + 1 << " " << ansR + 1 << "\n";

    return 0;
}
