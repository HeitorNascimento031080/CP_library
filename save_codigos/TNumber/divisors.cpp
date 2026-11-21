#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vvi vector<vector<pii>>
#define f first
#define s second
#define arr tuple<int, int , int>
const int MAXN = 2e5+3;
const int MAXA = 1e7+3;

// div factors primes
void ini(int n, vector<pii>& divp){
    int val =n;
    for(int i = 2; i*i<=n; i++){
        if(val%i) continue;
        int cont = 0;
        while(!(val%i)){
            val/=i;
            cont++;
        }
        divp.push_back({i, cont});
    }
    if(val>1) divp.push_back({val, 1});
}

// div factors
void ini2(int n, vector<int>& div){
    for(int i=1; i*i<=n; i++){
        if(n%i) continue;
        div.push_back(i);
        if(n/i!=i) div.push_back(n/i);
    }
}

void solve(){
    vector<int> a; vector<pii> b;
    int x; cin>>x; ini(x, b); ini2(x, a);
    sort(a.begin(), a.end());
    for(auto& u:a) cout<<u<<" ";
    cout<<"\n";
    for(auto& [u,v]:b) cout<<u<<" "<<v<<"\n";
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<fixed<<setprecision(8);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}