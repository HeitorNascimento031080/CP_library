#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define f first
#define s second
#define arr tuple<int, int , int>
// #define double long double
const int MAXN = 1e4+3;
const int mod= 1e9+7;
// bool isprime[33];
// vector<int> nums;

//Throwing Dice

int mod_mul(int a, int b){
    return ((a%mod)*(b%mod))%mod;
}

int mod_sum(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}

vvi mul_mat(vvi& a, vvi& b){
    vector<int> as(6);
    vvi ans(6, as);
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            for(int k=0; k<6; k++){
                ans[i][j] = mod_sum(ans[i][j],mod_mul(a[i][k], b[k][j]));
            }

        }
    }
    return ans;
}


vvi fexp(vvi& a, int k){
    vector<int> ip(6);
    vvi ret(6, ip);
    for(int i=0; i<6; i++){
        ret[i][i]++;
    }
    while(k){
        if(k&1) ret=mul_mat(ret, a);
        a=mul_mat(a,a);
        k/=2; 
    }
    return ret;
}


void solve(){
    int n; cin>>n;
    vvi rel ={
{1,1,1,1,1,1},
{1,0,0,0,0,0},
{0,1,0,0,0,0},
{0,0,1,0,0,0},
{0,0,0,1,0,0},
{0,0,0,0,1,0}
};  
    vector<int> bas ={1,2,4,8,16,32};
    if(n<7){
        cout<<bas[n-1]<<"\n";
    }
    else{
        rel =fexp(rel, n-6);
        int ans = 0;
        for(int i=0; i<6; i++){
            ans =mod_sum(ans, mod_mul(rel[0][i], bas[5-i]));
        }
        cout<<ans<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout<<fixed<<setprecision(8);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t =1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}