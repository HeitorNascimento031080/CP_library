#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int,int,int>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>

const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5;
using ld = long double;

int a[MAXN];
int n, s;
int ans = 0;
void solve(){
    int i =0;
    int j =0;
    int val =0;
    while(j<n){
        val+=a[j];
        while(val>s){
            val-=a[i];
            i++;
        }
        ans = max(ans, j-i+1);
        j++;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(8);
    cin>>n>>s; 
    for(int i=0; i<n; i++) cin>>a[i];
    solve();
    cout<<ans<<"\n";


    
    return 0;
} 