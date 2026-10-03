#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
using mtuple = tuple<int, int, char>;
#define vt vector<tuple>
#define pqueue priority_queue<mtuple, vector<mtuple>, greater<mtuple>>

const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+3;

int a[MAXN];
int n, k; 
int subps(){
    map<int, int> se = {{0,1}};
    int num =0;
    int mir;
    for(int i=1; i<=n; i++){
        mir = a[i]-k;
        if(se.count(mir)){
            num+=se[mir];
        }
        if(se.count(a[i])) se[a[i]]++;
        else se[a[i]] =1;
    }
    return num;
}


void solve(){  
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=0; i<n; i++) a[i+1]+=a[i];
    int ans = subps();
    cout<<ans<<"\n";
}




signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout<<fixed<<setprecision(13);
    // int t; cin>>t;
    // while(t--){
    //     solve();
    // }
    solve();
    return 0;
 
} 