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

// smallest prime factor
// int spf[MAXA];
// void ini(){
//     for(int i=2; i<MAXA; i++) spf[i] = i;
//     for(int i=2; i*i<MAXA; i++){
//         if(spf[i]!=i) continue;
//         for(int j=i+i; j<MAXA; j+=i){
//             if(spf[j]==j) spf[j] = i;
//         }
//     }
// }

// nums div factors
// int ndiv[MAXN];
// void ini(){
//     for(int i=1; i<MAXN; i++){
//         for(int j=i; j<MAXN; j+=i){
//             ndiv[j]++;
//         }
//     }
// }

// é primo?
bool isprime[MAXN];
vector<int> prime;
void ini(){
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for(int i=2; i<MAXN; i++){
        if(!isprime[i]) continue;
        prime.push_back(i);
        for(int j=i+i; j<MAXN; j+=i){
            isprime[j]=0;
        }
    }
}

void solve(){
    for(auto u:prime) cout<<u<<"\n";
}


signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<fixed<<setprecision(8);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ini();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}