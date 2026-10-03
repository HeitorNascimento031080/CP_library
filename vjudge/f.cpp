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
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> sa(n+1);
    vector<int> sb(n+1);
    string x; cin>>x;
    for(int i=0; i<(int)x.size(); i++){
        if(x[i]=='0'){
            a[i+1] = 2;
            b[i+1] = 1;
        }
        else{
            a[i+1] =1;
            b[i+1] =2;
        }  
    }
    int a1; int a2; int b1; int b2;
    a1 =0; a2 =0; b1 =0; b2=0;
    int j = n/2;
    while(j<n){
        if(x[j]=='0') a1++;
        else break;
        j++;
    }
    j = n/2;

    while(j<n){
        if(x[n-1-j]=='0') a2++;
        else break;
        j++;
    }
    j = n/2;
    while(j<n){
        if(x[j]=='1') b1++;
        else break;
        j++;
    }
    j = n/2;
    while(j<n){
        if(x[n-j-1]=='1') b2++;
        else break;
        j++;
    }
    for(int i=1; i<=n; i++){
        sa[i] = sa[i-1]+a[i];
        sb[i] = sb[i-1]+b[i];
    }
    int ans, num1, num2;
    if(!(n%2)){
        num1 = sa[n/2]+(sa[n]-sa[n/2]) - ((a1+a2)*2);
        num2 = sb[n/2]+(sb[n]-sb[n/2]) - ((b1+b2)*2);
        ans = min(num1, num2);
    }
    else{
        num1 = sa[(n+1)/2]+(sa[n]-sa[n/2]) - (max((a1+a2), (int)0)*2);
        num2 = sb[(n+1)/2]+(sb[n]-sb[n/2]) - (max((b1+b2), (int)0)*2);
        ans = min(num1, num2); 
    }
    cout<<ans<<"\n";

    return;

}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}