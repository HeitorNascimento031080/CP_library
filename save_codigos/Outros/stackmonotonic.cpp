#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
using mtuple = tuple<int, int, char>;
#define vt vector<tuple>
#define pqueue priority_queue<int, vector<int>, greater<int>>

const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+3;

void solve(){  
    int n; cin>>n;
    vector<int> v(n);
    for(int& i:v) cin>>i;
    vector<int> l(n, -1);
    vector<int> r(n, n);
    stack<int> a;
    //menor à esquerda
    for(int i=0; i<n; i++){
        while(!a.empty()&&v[i]>=a.top()){
            a.pop();
        }
        if(!a1.empty()){
            l[i] = a.top();
        }
        a.push(i);
    }
    //limpar a pilha
    while(!a.empty()) a.pop();
    // menor à direita
    for(int i=n-1; i>=0; i--){
        while(!a.empty()&&v[i]>=a.top()){
            a.pop();
        }
        if(!a1.empty()){
            r[i] = a.top();
        }
        a.push(i);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans= max(ans,v[i]*(r[i]-l[i]+1));
    }
    cout<<ans<<"\n";
    return;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}