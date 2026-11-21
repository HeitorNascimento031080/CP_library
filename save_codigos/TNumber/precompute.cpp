#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int MAXN = 2e6+5;
int fact[MAXN];
int ifact[MAXN];

// Distributing Apples 

int mod_mul(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}

int fexp(int a, int b){
    int ret = 1;
    while(b){
        if(b&1) ret =mod_mul(ret, a);
        a =mod_mul(a,a);
        b/=2;
    }
    return ret;
}

int inv(int a){
    return fexp(a, mod-2);
}


void ini(){
    fact[0] =1; fact[1]=1;
    ifact[0] =1; ifact[1]=1;
    for(int i=2; i<MAXN; i++){
        fact[i] = mod_mul(i, fact[i-1]);
        ifact[i] = inv(fact[i]);
    }
}

void solve(){
    int n,k; cin>>n>>k;
    cout<<mod_mul(fact[n-1+k],mod_mul(ifact[k], ifact[n-1]))<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ini();
    int t =1; 
    //cin>>t;
    while(t--) solve();
    
    return 0;
}