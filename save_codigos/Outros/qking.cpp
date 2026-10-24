#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];      // Grafo original
vector<int> rev_adj[MAXN];  // Grafo reverso
bool vis[MAXN];

vector<int> order;          // Guarda a ordem de finalizacao da DFS 1
int kingdom[MAXN];          // Guarda a resposta (ID do reino de cada planeta)

// DFS 1: Processa o grafo original e anota a ordem de término
void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    // O nó u só é adicionado APÓS visitar todos os seus caminhos
    order.push_back(u); 
}

// DFS 2: Pinta os reinos no grafo reverso
void dfs2(int u, int id) {
    vis[u] = true;
    kingdom[u] = id; // Associa o planeta ao Reino atual
    for (int v : rev_adj[u]) {
        if (!vis[v]) {
            dfs2(v, id);
        }
    }
}

void solve_kingdoms() {
    int n, m;
    if (!(cin >> n >> m)) return;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // Monta o grafo invertido simultaneamente
    }

    // PASSO 1: Descobrir a ordem de processamento (DFS 1)
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    // PASSO 2: Zerar o array de visitados para a segunda rodada
    memset(vis, false, sizeof(vis));
    
    // PASSO 3
