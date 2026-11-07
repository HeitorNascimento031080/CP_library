#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int nxt[MAXN], state[MAXN];
vector<int> rev_adj[MAXN];

// Estruturas do Ciclo
vector<int> cycle_nodes[MAXN];
int cycle_id[MAXN], cycle_pos[MAXN];
int cid_count = 0;

// Estruturas das Queries
struct Query { int k, id; };
vector<Query> queries[MAXN];
int ans[MAXN];

// Vetor que guarda a jornada do ciclo ate a folha atual
vector<int> path_hist;

void dfs_offline(int u) {
    path_hist.push_back(u);
    
    // Resolve TODAS as queries que partem deste nó
    for (auto q : queries[u]) {
        int depth = path_hist.size() - 1; // Distancia atual ate o ciclo
        
        if (q.k <= depth) {
            // Se os passos cabem na arvore, pega do historico (anda k pra tras na pilha)
            ans[q.id] = path_hist[depth - q.k];
        } else {
            // Se o k transborda a arvore, ele vai girar no ciclo
            int rem_k = q.k - depth;
            int root = path_hist[0]; // O nó do ciclo que ancora esta arvore
            
            int cid = cycle_id[root];
            int pos = cycle_pos[root];
            int len = cycle_nodes[cid].size();
            
            // Matematica do ciclo circular
            ans[q.id] = cycle_nodes[cid][(pos + rem_k) % len];
        }
    }
    
    // Continua subindo pelas arvores invertidas
    for (int v : rev_adj[u]) {
        dfs_offline(v);
    }
    
    path_hist.pop_back(); // Backtracking do historico
}

void solve_queries_1() {
    int n, q; 
    if(!(cin >> n >> q)) return;

    for (int i = 1; i <= n; i++) cin >> nxt[i];
    
    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        queries[x].push_back({k, i});
    }

    // PASSO 1: Isolar Ciclos (Mesma logica do Cycles, mas guardando os arrays)
    for (int i = 1; i <= n; i++) {
        if (state[i]) continue;
        vector<int> p;
        int curr = i;
        while (state[curr] == 0) {
            state[curr] = 1;
            p.push_back(curr);
            curr = nxt[curr];
        }
        if (state[curr] == 1) {
            cid_count++;
            auto it = find(p.begin(), p.end(), curr);
            int pos = 0;
            for (auto it2 = it; it2 != p.end(); it2++) {
                cycle_id[*it2] = cid_count;
                cycle_pos[*it2] = pos++;
                cycle_nodes[cid_count].push_back(*it2);
            }
        }
        for (int u : p) state[u] = 2;
    }

    // PASSO 2: Inverter arestas apenas das arvores
    for (int i = 1; i <= n; i++) {
        if (cycle_id[i] == 0) rev_adj[nxt[i]].push_back(i);
    }

    // PASSO 3: Iniciar as respostas offline partindo apenas das raizes (nós de ciclo)
    for (int i = 1; i <= n; i++) {
        if (cycle_id[i] != 0) dfs_offline(i);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve_queries_1();
    return 0;
}
