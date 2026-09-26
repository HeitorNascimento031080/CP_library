#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int, int>
#define vt vector<tuple>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>

const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5+10;


// vector<pii> adj[MAXN];
// int dist[MAXN];
// void dijkstra(){
//     memset(dist, bit, sizeof(dist));
//     dist[0] = 0;
//     pqueue pq; pq.push({dist[0],0});
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


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout<<fixed<<setprecision(8);
    int n, k; cin>>n>>k;
    for(int i=0; i<n; i++) cin>>a[i];

    return 0;
 
} 