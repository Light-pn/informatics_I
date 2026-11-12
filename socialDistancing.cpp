
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool possible(long long d, vector<pair<long long, long long>>& a, int n) {
    long long last = 0;
    int cows = 0;

    for (int i = 0; i < a.size(); i++) {
        long long l = a[i].first;
        long long r = a[i].second;
        long long pos;

        if (cows == 0) {
            pos = l;
        } else {
            pos = max(l, last + d);
        }

        while (pos <= r) {
            cows++;

            if (cows == n) {
                return true;
            }

            last = pos;
            pos += d;
        }
    }

    return false;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> a(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    long long l = 1;
    long long r = a[m - 1].second - a[0].first;
    long long ans = 0;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (possible(mid, a, n)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
