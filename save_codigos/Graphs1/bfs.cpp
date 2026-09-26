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
const int MAXN2 = 1e3+10; 

vector<int> adj[MAXN];
int dist[MAXN];
int vis[MAXN];

char adj2[MAXN2][MAXN2];
int dist2[MAXN2][MAXN2];
int n, m;


bool valid(int a, int b){
    return a>=0&&b>=0&&a<n&&b<m&&dist2[a][b]==-1&&
        adj2[a][b]!='#';
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

void bfs(int x){
    memset(dist, -1, sizeof(dist));
    vis[x] =1;
    dist[x] = 0;
    queue<int> q; q.push(x); 
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                dist[v] = dist[u]+1;
                q.push(v);
                vis[v] =1;
            }
        }
    }
}

void bfs_grid(pii x){
    memse(dist2, -1, sizeof(dist2));
    dist2[x.f][x.s] = 0;
    queue<pii> q; q.push(x);
    while(!q.empty()){
        auto [u1, u2] = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int ax = u1+dx[i];
            int ay = u2+dy[i];
            if(valid(ax,ay)){
                q.push({ax,ay});
                dist2[ax][ay] = dist2[u1][u2]+1;
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //receba
    return 0;
} 