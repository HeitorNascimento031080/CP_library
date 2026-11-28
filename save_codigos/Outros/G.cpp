
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int w = k - (n - 1);

    if (w < 0 || w > (n - 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int d = j - i;

            if (d <= w) {
                cout << i + 1 << " > " << j + 1 << '\n';
            }
            else if (n - d <= w) {
                cout << i + 1 << " < " << j + 1 << '\n';
            }
            else {
                cout << i + 1 << " = " << j + 1 << '\n';
            }
        }
    }

    return 0;
}
