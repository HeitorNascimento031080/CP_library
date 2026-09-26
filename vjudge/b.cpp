#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int, int>
#define vt vector<tuple>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>

const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e7+10;





signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cout<<fixed<<setprecision(8);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int cont =0;
        vector<int> a;
        bool cond = false;
        for(int i=0; i<n;i++){
            char x; cin>>x;
            if(x=='#') cont++;
            else{
                if(cont!=0&&cont!=1&&cont!=2) a.push_back(cont);
                if(cont==1||cont==2) cond=true;
                cont = 0;
            }
        }
        if(cont!=0&&cont!=1&&cont!=2) a.push_back(cont);
        int ans =0;
        if(cond) ans++;
        for(int i=0; i<(int)a.size(); i++){
            ans += (a[i]/2)+(a[i]%2);
        }
        cout<<ans<<"\n";
    }
        
    return 0;
 
} 