
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int s, vector<vector<int>>& g) {
    int n = g.size() - 1;

    vector<int> dist(n + 1, -1);
    queue<int> q;

    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (dist[v] != -1) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);

        edges.push_back({u, v});
    }

    vector<int> d1 = bfs(1, g);
    vector<int> dn = bfs(n, g);

    int D = d1[n];

    for (auto [u, v] : edges) {
        if (d1[u] != -1 && dn[v] != -1 &&
            d1[u] + 1 + dn[v] == D + 1) {
            cout << "possible\n";
            return 0;
        }

        if (d1[v] != -1 && dn[u] != -1 &&
            d1[v] + 1 + dn[u] == D + 1) {
            cout << "possible\n";
            return 0;
        }
    }

    cout << "impossible\n";

    return 0;
}
