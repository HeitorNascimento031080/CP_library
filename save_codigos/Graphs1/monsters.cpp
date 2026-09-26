
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
const int MAXN = 1e3+10;

char adj[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
char dir[MAXN][MAXN];
pii pai[MAXN][MAXN];
map<pii, char> mov1{{{0, 1}, 'R'}, {{-1, 0}, 'U'},{{0,-1}, 'L'}, {{1, 0}, 'D'}};
vector<pii> mov = {{0, 1}, {-1, 0}, {0,-1}, {1, 0}};
 

int n, m;
 
bool valid(int a, int b){
    return a<n&&b<m&&a>=0&&b>=0&&adj[a][b]!='#'&&!vis[a][b];
}
void bfs_ms(vector<pii> u){
    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    queue<pii> q; 
    for(auto y: u){
        q.push(y); vis[y.f][y.s] = true; dist[y.f][y.s] = 0;
    }
    while(!q.empty()){
        pii v = q.front(); q.pop();
        for(auto x: mov){
            x.f+=v.f; x.s+=v.s;
            if(valid(x.f, x.s)){
                q.push({x.f, x.s}); 
                dist[x.f][x.s] = dist[v.f][v.s]+1;
                vis[x.f][x.s] = true;
            }
        }
    }
}
 
 
pii bfs(pii u){
    memset(vis, false, sizeof(vis));
    pai[u.f][u.s] = {u.f, u.s};
    vis[u.f][u.s] = true;
    dist[u.f][u.s] = 0;
    queue<pii> q;
    q.push(u);
    while(!q.empty()){
        pii v = q.front(); q.pop();
        if(v.f==n-1||v.f==0||v.s==m-1||v.s==0){
            return {v.f, v.s};
        } 
        for(auto x:mov){
            int ax = x.f+v.f; int ay = x.s+v.s;
            if(valid(ax, ay)&&(dist[v.f][v.s]+1<dist[ax][ay]||dist[ax][ay]==-1)){
                vis[ax][ay] = true;
                dist[ax][ay] = dist[v.f][v.s]+1;
                pai[ax][ay] = v;
                dir[ax][ay] = mov1[x]; 
                q.push({ax, ay}); 
            }
        }
    }
    return {-1, -1};
}
 
string camin(pii u, pii fi){
    string ans ="";
    pii a = fi;
    while(a!=u){
        ans += dir[a.f][a.s];
        a = pai[a.f][a.s];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vector<pii> a;
    pii b;
    for(int i =0;i<n;i++){
        for(int j = 0; j<m; j++){
            char x; cin>>x; 
            if(x=='M') a.push_back({i,j});
            else if(x=='A') b = {i,j};
            adj[i][j]=x;
        }
    }
    bfs_ms(a);
    pii cords = bfs(b);
    if(cords.f==-1) cout<<"NO"<<"\n";
    else{
        string c = camin(b, cords);
        cout<<"YES"<<"\n"<<dist[cords.f][cords.s]<<"\n"<<c<<"\n";
    }
    return 0;
}