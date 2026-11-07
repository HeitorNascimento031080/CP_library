#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int nxt[MAXN], ans[MAXN], state[MAXN];

void solve_cycles() {
    int n; 
    if(!(cin >> n)) return;

    for (int i = 1; i <= n; i++) cin >> nxt[i];

    for (int i = 1; i <= n; i++) {
        if (state[i]) continue;
        
        vector<int> path;
        int curr = i;
        
        // Caminha ate achar alguem ja processado ou da propria iteracao
        while (state[curr] == 0) {
            state[curr] = 1;
            path.push_back(curr);
            curr = nxt[curr];
        }
        
        // Se bateu em um no com state 1, fechou um ciclo agora
        if (state[curr] == 1) {
            int start_idx = -1;
            for (int j = 0; j < path.size(); j++) {
                if (path[j] == curr) {
                    start_idx = j;
                    break;
                }
            }
            int cycle_len = path.size() - start_idx;
            for (int j = start_idx; j < path.size(); j++) {
                ans[path[j]] = cycle_len; // Todo mundo do ciclo tem a mesma resposta
            }
        }
        
        // Processa as "caudas" (arvores) de tras pra frente
        for (int j = (int)path.size() - 1; j >= 0; j--) {
            if (ans[path[j]] == 0) {
                ans[path[j]] = ans[nxt[path[j]]] + 1;
            }
            state[path[j]] = 2; // Marca como totalmente processado
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve_cycles();
    return 0;
}
