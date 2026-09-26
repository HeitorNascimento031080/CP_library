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
const int MAXN = 2e5+10;
using ld = long double;


int n;

int cont[MAXN];
int sum[MAXN];
//Two TVs
bool solve(vector<int>& a, vector<pii>& b){
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for(auto [u,v]:b){
        int a1 = lower_bound(a.begin(), a.end(), u) - a.begin();
        int a2 = lower_bound(a.begin(), a.end(), v) - a.begin();
        cont[a1]++; cont[a2]--;
    }
    sum[0] = cont[0];
    for(int i=0; i<n-1;i++){
        sum[i+1] = sum[i]+cont[i+1];
    }
    int mx = 0;
    for(int i =0; i<n;i++){
        mx = max(sum[i], mx);
    }
    if(mx>2) return false;
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(8);
    cin>>n; 
    vector<int> num;
    vector<pii> par;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        par.push_back({x,y+1});
        num.push_back(x); num.push_back(y+1);
    } 
    if(solve(num, par)) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
        
    return 0;
} 