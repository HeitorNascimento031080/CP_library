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

const int MAXN = 1e9;
int ans = 1e9;
void binary_search(int x){
    int l = 0; int r = MAXN;
    while(l<=r){
        int mid = (l+r)/2;
        if(mid<=x){
            ans = mid;
            l= mid+1;
        }
        else r = mid-1;
        cout<<mid<<" ";
    }
    cout<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    binary_search(n);
    cout<<ans<<"\n";
    return 0;
} 