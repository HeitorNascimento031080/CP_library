#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int,int,int>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>
const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5+10;

vector<int> adj[MAXN];
int vis[MAXN];
int color[MAXN];
int pai[MAXN];
void dfs(int u){ 
    vis[u] = 1;
    for(auto v: adj[u])
        if(!vis[v]) dfs(v);
}

bool dfs_color(int u){ // bicoloridade
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]){
            color[v] = !color[u];
            if(!dfs_color(v)) return false;
        } 
        else if(color[v]==color[u]) return false;
    }
    return true;
}

int idx1 = -1; //começa
int idx2 = -1; //termina

bool ciclo1(int u, int ante){ //ciclo não direcionado
    vis[u] = 1; 
    for (int v : adj[u]){
        if (v==ante) continue; 
        if (vis[v]){
            idx2 = u;
            idx1 = v;
            return true;
        }
        
        pai[v] = u;
        if (ciclo1(v, u)) return true;
    }
    
    return false;
}

bool ciclo2(int u){ //ciclo direcionado
    vis[u] = 1; 
    for(int v : adj[u]){
        if(!vis[v]){
            pai[v] = u;
            if (ciclo2(v, u)) return true;
        }
        else if(vis[v]==1){
            idx2 = u;
            idx1 = v;
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin>>n>>m;
    cout<<-1<<"\n";
    return 0;
} 