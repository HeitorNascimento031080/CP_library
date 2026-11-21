#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
using mtuple = tuple<int, int, char>;
#define vt vector<tuple>
#define pqueue priority_queue<int, vector<int>, greater<int>>
const int MAXN  =1e5+4;
int a[MAXN];
int seg[4*MAXN];

int build(int p, int l, int r){
    if(l==r) return seg[p] = a[l];
    int mid = (l+r)/2;
    return seg[p] = build(2*p+1, l, mid)+build(2*p+2, mid+1, r);
}

int qy(int i, int j, int p, int l, int r){
    if(l>j||r<i) return 0;
    if(l>=i&&r<=j) return seg[p];
    int mid = (l+r)/2;
    return build(i,j,2*p+1, l, mid)+build(i,j,2*p+2, mid+1, r);
}

int upd(int i, int x, int p, int l, int r){
    if(l>i||r<i) return 0;
    if(l==r) return seg[p] = x;
    int mid = (l+r)/2;
    return seg[p] = build(i,x,2*p+1, l, mid)+build(i,x,2*p+2, mid+1, r);
}

void solve(){
    int n, q; cin>>n>>q;
    for(int i=0; i<n; i++) cin>>a[i];
    build(0, 0, n-1);
    while(q--){
        int id, u, v; cin>>id>>u>>v;
        if(id==1){
            upd(u, v, 0, 0, n-1);
        }
        else{
            cout<<qy(u,v-1, 0, 0, n-1)<<"\n";
        }
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