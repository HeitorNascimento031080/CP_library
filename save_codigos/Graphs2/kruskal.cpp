#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int, int, int>
#define vt vector<tuple>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>

const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 3e5+10;

int id[MAXN];
int sz[MAXN];

int find(int x){
    if(id[x]==x) return x;
    return id[x]= find(id[x]);
  //return find(id[x]); (sem otmização)
}
bool uni(int x, int y){
    x= find(x); y =find(y);
    if(x==y) return false;
    // if(sz[x]<sz[y]) swap(x,y); (otimização)
    id[y] = x; 
    // sz[x]+=sz[y]; (otimização)
    return true;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout<<fixed<<setprecision(8);
    int n, m; cin>>n>>m;
    for(int i=0;i<n; i++) {
        id[i]=i; sz[i] =1;
    }
    vt p;
    for(int i=0;i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        p.emplace_back(c,a-1,b-1);
    }
    sort(p.begin(),p.end());
    int ans =0;
    for(auto [w, u, v]: p){
        if(uni(u,v)) ans+=w;
    }
    cout<<ans<<"\n";

    
    
    return 0;
} 