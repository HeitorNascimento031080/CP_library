
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<int>> bandas(n + 1);
    vector<vector<int>> pessoas(m + 1);

    vector<int> grauBanda(n + 1, 0);
    vector<int> grauPessoa(m + 1, 0);
    vector<int> original(m + 1, 0);

    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;

        original[i] = k;
        grauPessoa[i] = k;

        for (int j = 0; j < k; j++) {
            int b;
            cin >> b;

            pessoas[i].push_back(b);
            bandas[b].push_back(i);

            grauBanda[b]++;
        }
    }

    vector<bool> ativaBanda(n + 1, true);
    vector<bool> ativaPessoa(m + 1, true);

    queue<pair<int, int>> q;

    // Tipo 0 = banda
    // Tipo 1 = pessoa

    for (int i = 1; i <= n; i++) {
        if (grauBanda[i] < c) {
            q.push({0, i});
        }
    }

    while (!q.empty()) {
        auto [tipo, u] = q.front();
        q.pop();

        if (tipo == 0) {
            if (!ativaBanda[u]) continue;

            ativaBanda[u] = false;

            // Cada pessoa perde uma favorita disponível.
            for (int p : bandas[u]) {
                if (!ativaPessoa[p]) continue;

                grauPessoa[p]--;

                if (2 * grauPessoa[p] < original[p]) {
                    q.push({1, p});
                }
            }
        }
        else {
            if (!ativaPessoa[u]) continue;

            ativaPessoa[u] = false;

            // A pessoa deixa de contar como fã.
            for (int b : pessoas[u]) {
                if (!ativaBanda[b]) continue;

                grauBanda[b]--;

                if (grauBanda[b] < c) {
                    q.push({0, b});
                }
            }
        }
    }

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (ativaBanda[i]) {
            ans.push_back(i);
        }
    }

    if (ans.empty()) {
        cout << "impossible\n";
    }
    else {
        cout << "possible\n";
        cout << ans.size() << '\n';

        for (int b : ans) {
            cout << b << ' ';
        }

        cout << '\n';
    }

    return 0;
}
