
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, v;
        cin >> n >> v;

        vector<vector<int>> g(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, w;
            cin >> u >> w;

            g[u].push_back(w);
            g[w].push_back(u);
        }

        // Monta a árvore a partir do vértice 1.
        vector<int> parent(n + 1, 0);
        vector<int> ordem;

        stack<int> st;
        st.push(1);
        parent[1] = -1;

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            ordem.push_back(u);

            for (int w : g[u]) {
                if (w == parent[u]) continue;

                parent[w] = u;
                st.push(w);
            }
        }

        // Matching guloso de baixo para cima.
        vector<bool> matched(n + 1, false);
        vector<bool> cutChild(n + 1, false);

        int qtd = 0;

        for (int i = n - 1; i >= 1; i--) {
            int u = ordem[i];
            int p = parent[u];

            if (!matched[u] && !matched[p]) {
                matched[u] = true;
                matched[p] = true;

                cutChild[u] = true;
                qtd++;
            }
        }

        if (qtd < v - 1) {
            cout << "NAO\n";
            continue;
        }

        // Cortamos exatamente v-1 arestas do matching.
        int cortes = 0;

        for (int i = 1; i <= n; i++) {
            if (cutChild[i]) {
                cortes++;

                if (cortes == v - 1) {
                    break;
                }
            }
        }

        // Identifica os componentes após os cortes.
        vector<int> cor(n + 1, 0);
        int id = 0;

        for (int i = 1; i <= n; i++) {
            if (cor[i] != 0) continue;

            id++;

            stack<int> pilha;
            pilha.push(i);
            cor[i] = id;

            while (!pilha.empty()) {
                int u = pilha.top();
                pilha.pop();

                for (int w : g[u]) {
                    if (cor[w] != 0) continue;

                    // Verifica se a aresta foi cortada.
                    if (parent[w] == u && cutChild[w]) {
                        continue;
                    }

                    if (parent[u] == w && cutChild[u]) {
                        continue;
                    }

                    cor[w] = id;
                    pilha.push(w);
                }
            }
        }

        cout << "SIM\n";

        for (int i = 1; i <= n; i++) {
            cout << cor[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
