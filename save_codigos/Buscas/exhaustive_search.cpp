#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int,int,int>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>
#define all(_) _.begin(), _.end()
const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e12;
const int MAXN = 20;
using ld = long double;

int a[MAXN];
int n, x, d;
int ans = 0;

void permutation(){ // n<=11 (numeros distintos) 
    vector<int> a = {0, 1, 1, 1}; // Com muita repetição é bem mais rápido
    vector<int> b = {1, 2, 3}; // Deve estar ordenado
    do{
        for(auto r:b) cout<<r<<" ";
        cout<<"\n";
    }while(next_permutation(all(b)));
    do{
        for(auto r:a) cout<<r<<" ";
        cout<<"\n";
    }while(next_permutation(all(a)));
}

// Coach
int bitmask(){ // n<=22
    int mx, mn, sum;
    int cont =0;
    for(int mask=0; mask<(1<<n); mask++){
        mx = -INF; mn = INF; sum =0; 
        for(int i=0; i<n; i++){
            if(mask&(1<<i)){
                // Está no subconjunto
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
                sum+=a[i];
            }
        }
        if(sum>=x&&(mx-mn)<=d) cont++;
    }
    return cont;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(8);
    cin>>n>>x>>d; 
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<bitmask()<<"\n";

    return 0;
} 