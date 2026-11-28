
#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<vector<int>>& g) {
    vector<int> ordem;
    queue<int> q;

    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ordem.push_back(u);

        for (int v : g[u]) {
            q.push(v);
        }
    }

    reverse(ordem.begin(), ordem.end());

    return ordem;
}

void cobrir(int u, vector<vector<int>>& g, vector<bool>& vis) {
    stack<int> st;
    st.push(u);

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (vis[v]) continue;

        vis[v] = true;

        for (int x : g[v]) {
            st.push(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n + 1);
    vector<int> parent(n + 1);

    parent[1] = 1;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        parent[i] = p;
        g[p].push_back(i);
    }

    vector<int> ordem = bfs(n, g);

    vector<bool> vis(n + 1, false);
    vector<int> ans;

    for (int u : ordem) {
        if (vis[u]) continue;

        int v = u;

        // Sobe k-1 ancestrais, ou até chegar na raiz.
        for (int j = 0; j < k - 1 && v != 1; j++) {
            v = parent[v];
        }

        ans.push_back(v);

        cobrir(v, g, vis);
    }

    cout << ans.size() << '\n';

    for (int v : ans) {
        cout << v << ' ';
    }

    cout << '\n';

    return 0;
}
