#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
using mtuple = tuple<int, int>;
#define vt vector<tuple>
#define pqueue priority_queue<mtuple, vector<mtuple>, greater<mtuple>>
const int MAXN  =2e5+4;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;

mt19937 rgn((signed)chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rgn);
}

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int& i:a) cin>>i;
    for(int& i:b) cin>>i;
    map<int, int> c, d;
    vector<int> a1(n+1), a2(n+1);
    for(int i=0; i<n; i++){
        if(!d.count(a[i])) d[a[i]] = uniform(1, 1e18);
        if(!d.count(b[i])) d[b[i]] = uniform(1, 1e18); 
    }
    c=d;
    for(int i=1;i<=n; i++){
        a1[i] = a1[i-1]^c[a[i-1]];
        c[a[i-1]] = 0;
        a2[i] = a2[i-1]^d[b[i-1]];
        d[b[i-1]] = 0;   
    }
    int q; cin>>q;
    while(q--){
        int x, y; cin>>x>>y;
        if(a1[x]^a2[y]) cout<<"No"<<"\n";
        else cout<<"Yes"<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t =1;
    // cin>>t;
    while(t--) solve();
}