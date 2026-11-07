#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int nxt[MAXN];
int state[MAXN]; // 0 = nao visitado, 1 = visitando, 2 = processado

// Dados dos Ciclos
int cycle_id[MAXN];
int cycle_pos[MAXN];
int cycle_len[MAXN];
int cid_count = 0;

// Dados das Arvores
vector<int> rev_adj[MAXN];
int root[MAXN];  // A qual no do ciclo esta arvore se conecta?
int depth[MAXN]; // Distancia ate o ciclo
int tin[MAXN], tout[MAXN];
int timer = 0;

// DFS para calcular profundidade e ancestralidade nas arvores
void dfs_tree(int u, int r, int d) {
    root[u] = r;
    depth[u] = d;
    tin[u] = ++timer;
    for (int v : rev_adj[u]) {
        dfs_tree(v, r, d + 1);
    }
    tout[u] = ++timer;
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    for (int i = 1; i <= n; i++) {
        cin >> nxt[i];
    }

    // PASSO 1: Detectar todos os ciclos
    for (int i = 1; i <= n; i++) {
        if (state[i] != 0) continue;
        
        vector<int> path;
        int curr = i;
        while (state[curr] == 0) {
            state[curr] = 1;
            path.push_back(curr);
            curr = nxt[curr];
        }
        
        // Se bateu em um no da propria jornada atual, achou ciclo!
        if (state[curr] == 1) {
            cid_count++;
            auto it = find(path.begin(), path.end(), curr);
            int len = 0;
            int pos = 0;
            // Marca todo mundo que faz parte do ciclo
            for (auto it2 = it; it2 != path.end(); it2++) {
                cycle_id[*it2] = cid_count;
                cycle_pos[*it2] = pos++;
                len++;
            }
            for (auto it2 = it; it2 != path.end(); it2++) {
                cycle_len[*it2] = len;
            }
        }
        // Marca o caminho todo como processado
        for (int u : path) state[u] = 2;
    }

    // PASSO 2: Montar as arvores invertidas (ignora as arestas do ciclo)
    for (int i = 1; i <= n; i++) {
        if (cycle_id[i] == 0) { // Se 'i' eh arvore, ele aponta pra nxt[i]
            rev_adj[nxt[i]].push_back(i);
        }
    }

    // PASSO 3: Rodar a DFS invertida a partir de cada no que pertence a um ciclo
    for (int i = 1; i <= n; i++) {
        if (cycle_id[i] != 0) {
            dfs_tree(i, i, 0); // (no atual, raiz no ciclo, profundidade)
        }
    }

    // PASSO 4: Responder as Queries em O(1)
    while (q--) {
        int a, b;
        cin >> a >> b;

        // Caso 1: Destino (B) esta num ciclo
        if (cycle_id[b] != 0) {
            // A raiz da arvore de A tem que estar no MESMO ciclo de B
            if (cycle_id[root[a]] != cycle_id[b]) {
                cout << -1 << "\n";
            } else {
                int r = root[a];
                // Distancia no anel do ciclo: (posB - posA + comp) % comp
                int dist_ciclo = (cycle_pos[b] - cycle_pos[r] + cycle_len[b]) % cycle_len[b];
                cout << depth[a] + dist_ciclo << "\n";
            }
        } 
        // Caso 2: Destino (B) esta numa arvore
        else {
            // Eles precisam estar na mesma arvore E B precisa ser ancestral de A
            if (root[a] == root[b] && tin[b] <= tin[a] && tout[b] >= tout[a]) {
                cout << depth[a] - depth[b] << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
