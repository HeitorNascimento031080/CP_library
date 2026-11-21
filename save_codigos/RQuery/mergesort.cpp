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
const int MAXN  =2e5+4;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;

vector<int> merge(vector<int>& a, vector<int>& b){
    vector<int> c;
    int l=0, r=0;
    while(l<(int)a.size()&&r<(int)b.size()){
        if(a[l]<=b[r]){
            c.push_back(a[l]);
            l++;
        }
        else{
            c.push_back(b[r]);
            r++;            
        }
    }
    while(r<(int)b.size()){
        c.push_back(b[r]);
        r++;
    }
    while(l<(int)a.size()){
        c.push_back(a[l]);
        l++;
    }
    return c;
}

void msort(int& ans, int l, int r, vector<int>& a){
    if(l>=r) return;
    int mid = (l+r)/2;
    msort(ans,l, mid, a);
    msort(ans,mid+1, r, a);
    vector<int> esq;
    vector<int> dir;
    for(int i=l; i<=mid; i++){
        esq.push_back(a[i]);
    }
    for(int i=mid+1; i<=r; i++){
        dir.push_back(a[i]);
    }
    int val=0;
    for(auto& u:esq){
        while(val<(int)dir.size()&&dir[val]<u) val++;
        ans+=val;
    }
    vector<int> all = merge(esq, dir);
    for(int i =l; i<=r; i++){
        a[i] = all[i-l];
    }
}

void solve(){
    int n; cin>>n;
    while(n){
        vector<int> a(n);
        for(int& i:a) cin>>i;
        int ans =0;
        msort(ans,0, n-1, a);
        cout<<ans<<"\n";
        cin>>n;
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