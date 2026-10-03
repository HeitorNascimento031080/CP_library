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
    int n;cin>>n;
    vector<int> l(n, -1);
    vector<int> r(n, n);
    vector<int> v(n);
    stack<int> a1, id1, a2, id2;

    for(int& i:v) cin>>i;
    for(int i=0; i<n; i++){
        if(a1.empty()){
            a1.push(v[i]);
            id1.push(i);
        }
        else{
            if(v[i]<a1.top()){
                while(!a1.empty()){
                    if(v[i]>a1.top()) break;
                    int top = id1.top();
                    r[top] = i;
                    id1.pop();
                    a1.pop();
                }
                a1.push(v[i]);
                id1.push(i);
            }
            else{
                a1.push(v[i]);
                id1.push(i);  
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        if(a2.empty()){
            a2.push(v[i]);
            id2.push(i);
        }
        else{
            if(v[i]<a2.top()){
                while(!a2.empty()){
                    if(v[i]>a2.top()) break;
                    int top = id2.top();
                    l[top] = i;
                    id2.pop();
                    a2.pop();
                }
                a2.push(v[i]);
                id2.push(i);
            }
            else{
                a2.push(v[i]);
                id2.push(i);  
            }
        }
    }
    int ans = 0;
    cout<<"\n";
    for(int i=0; i<n; i++){
        ans+= v[i]*(r[i]-i)*(i-l[i]);
    }
    cout<<ans<<"\n";
    return;

}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);


    solve();
    return 0;
}