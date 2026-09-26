#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int,int, int>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>
const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+10;

// vector<pii> adj[MAXN];
// int dist[MAXN];

// Dijkstra resolve problemas que Bfs não resolve
// void dijkstra(int u){
//     memset(dist, bit, sizeof(dist));
//     dist[u] = 0;
//     pqueue pq; pq.push({dist[u],u});
//     while(!pq.empty()){
//         auto [d, v] = pq.top(); pq.pop();
//         if(d>dist[v]) continue;
//         for(auto [x, w]: adj[v]){
//             if(dist[x]>dist[v]+w){
//                 dist[x]= dist[v]+w;
//                 pq.push({dist[x], x});
//             }
//         }
//     }
// }

//Flip Edge
int n, m, x;
vector<int> adj[MAXN][2];
int dist[MAXN][2]; //num. de estados = 2 (0 && 1)
void dijkstra2(int i){
    memset(dist, bit, sizeof(dist));
    dist[i][0]=0;
    dist[i][1]=x;
    pqueue pq; pq.push({dist[i][0], i, 0});
    pq.push({dist[i][1], i, 1});
    while(!pq.empty()){
        auto [d, u, e] = pq.top();
        pq.pop();
        if(d>dist[u][e]) continue;
        for(auto v: adj[u][e]){
            if(dist[v][e]>dist[u][e]+1){
                dist[v][e] = dist[u][e]+1;
                pq.push({dist[v][e], v, e});
            }                
            if(dist[v][1-e]>dist[u][e]+1+x){
                dist[v][1-e] = dist[u][e]+1+x;
                pq.push({dist[v][1-e], v, 1-e});                    
            }
        } 
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(15); 
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int a, b; cin>>a>>b;
        adj[a-1][0].push_back(b-1);
        adj[b-1][1].push_back(a-1);
    }

    dijkstra2(0);
    int ans = min(dist[n-1][0], dist[n-1][1]);
    cout<<ans<<"\n";
    
    return 0;

}