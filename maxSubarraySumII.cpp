
#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> p(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        p[i] = p[i - 1] + x;
    }

    multiset<long long> s;
    long long ans = LLONG_MIN;

    for (int r = a; r <= n; r++) {
        s.insert(p[r - a]);

        if (r - b - 1 >= 0) {
            s.erase(s.find(p[r - b - 1]));
        }

        ans = max(ans, p[r] - *s.begin());
    }

    cout << ans << "\n";

    return 0;
}
