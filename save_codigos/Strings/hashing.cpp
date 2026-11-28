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
const int MAXN  =1e6+4;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const int P1 = 31;
const int P2 = 37;
const int M1 = 1e9+33;
const int M2 = 1e9+93;
int prefix_hash1[MAXN];
int prefix_hash2[MAXN];
int power1[MAXN];
int power2[MAXN];

// string matching

int mod_mul(int a, int b, int m){
    return (a*b)%m;
}

int mod_sub(int a, int b, int m){
    return (((a-b)%m)+m)%m;
}

pii hashs(vector<int>& s){
    int h1=0, h2=0;
    for(int i=0; i<(int)s.size(); i++){
        h1 = (h1*P1+s[i])%M1;
        h2 = (h2*P2+s[i])%M2;
    }
    return {h1, h2};
}

void hasher(vector<int>& s){
    for(int i=0; i<(int)s.size(); i++){
        int val = s[i];
        prefix_hash1[i+1] = (prefix_hash1[i]*P1+val)%M1;
        prefix_hash2[i+1] = (prefix_hash2[i]*P2+val)%M2;
    }
}

pii sub_hash(int l, int r){
    int len = r-l+1;
    int h1 = {mod_sub(prefix_hash1[r+1],mod_mul(prefix_hash1[l], power1[len], M1),M1)};
    int h2 = {mod_sub(prefix_hash2[r+1],mod_mul(prefix_hash2[l], power2[len], M2),M2)};
    return {h1, h2};
}

void ini(){
    power1[0]=1; power2[0]=1;
    for(int i=1; i<MAXN; i++){
        power1[i] = mod_mul(P1, power1[i-1], M1);
        power2[i] = mod_mul(P2, power2[i-1], M2);
    }
}

void solve(){
    string x, y; cin>>x>>y;
    int n = x.size(); int m = y.size();
    if(n<m){
        cout<<0<<"\n";
        return;
    }
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) a[i] = x[i]-'a'+1;
    for(int i=0; i<m; i++) b[i] = y[i]-'a'+1;
    int ans = 0;
    hasher(b);
    pii a1 = sub_hash(0, m-1);
    hasher(a);
    for(int i=0; i<n-m+1; i++){
        pii a2 = sub_hash(i, m-1+i);
        if(a1.f==a2.f&&a1.s==a2.s) ans++;
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ini();
    int t =1;
    // cin>>t;
    while(t--) solve();
}
