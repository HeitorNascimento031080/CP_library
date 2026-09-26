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


int t, k;
//encontrar a raiz (long double)
bool f(ld mid){
    if(mid*mid<=k) return true;
    else return false;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(8);
    cin>>t; 
    while(t--){
        cin>>k;
        ld l = 0.0; ld r = 1e9+10;
        ld ans = r;
        int rep = 200;
        while(rep--){
            ld mid = (l+r)/2;
            if(f(mid)){
                ans = mid;
                l = mid;
            }
            else r = mid;
        }
        cout<<ans<<"\n";
    }

    
    return 0;
} 