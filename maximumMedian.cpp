
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m = n / 2;

    for (int i = m; i < n - 1; i++) {
        long long need = (a[i + 1] - a[i]) * (i - m + 1);

        if (need <= k) {
            k -= need;
        } else {
            cout << a[i] + k / (i - m + 1) << "\n";
            return 0;
        }
    }

    cout << a[n - 1] + k / (n - m) << "\n";

    return 0;
}
