
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int ans = 0;

        for (int i = n; i >= 1; i--) {
            if (freq[i] > ans) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
