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
int deg[MAXN];
int n, m;
//course schedule
vector<int> toposort(){
    queue<int> q;
    for(int i=0; i<n; i++)
        if(!deg[i]) q.push(i);
    vector<int> ord;
    while(!q.empty()){
        int x = q.front(); q.pop();
        ord.push_back(x);
        for(auto v: adj[x]){
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
    }
    // se ord.size()!=n, não há ordenação possível!
    return ord;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;cin>>a>>b;
        adj[a-1].push_back(b-1);
        deg[b-1]++;
    }
    vector<int> ans = toposort();
    if((int)ans.size()!=n) cout<<"IMPOSSIBLE\n";
    else{
        for(auto g: ans) cout<<g+1<<" ";
        cout<<"\n";
    }
    return 0;
} 