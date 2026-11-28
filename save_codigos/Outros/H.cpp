
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int MAXN = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<bitset<MAXN + 1>> a(m);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        while (k--) {
            int x;
            cin >> x;
            a[i].set(x);
        }
    }

    vector<long long> fat(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        fat[i] = fat[i - 1] * i % MOD;
    }

    int total = 1 << m;

    vector<bitset<MAXN + 1>> uniao(total);

    long long ans = 0;

    for (int mask = 0; mask < total; mask++) {

        if (mask != 0) {
            int bit = __builtin_ctz(mask);
            int prev = mask & (mask - 1);

            uniao[mask] = uniao[prev] | a[bit];
        }

        int qtd = uniao[mask].count();

        if (__builtin_popcount((unsigned)mask) % 2 == 0) {
            ans += fat[n - qtd];
        }
        else {
            ans -= fat[n - qtd];
        }

        ans %= MOD;
    }

    ans = (ans + MOD) % MOD;

    cout << ans << '\n';

    return 0;
}
