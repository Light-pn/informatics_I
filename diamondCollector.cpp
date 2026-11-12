
#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> len(n), best(n + 1, 0);

    int r = 0;

    for (int l = 0; l < n; l++) {
        while (r < n && a[r] - a[l] <= k) {
            r++;
        }

        len[l] = r - l;
    }

    for (int i = n - 1; i >= 0; i--) {
        best[i] = max(best[i + 1], len[i]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int j = i + len[i];
        ans = max(ans, len[i] + best[j]);
    }

    cout << ans << "\n";

    return 0;
}
