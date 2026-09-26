#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int,int>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>
const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 310;


int n, m;
int adj[MAXN][MAXN];
void floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j =0; j<n; j++){
                if(adj[i][k]!=INF&&adj[k][j]!=INF){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(15); 
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            adj[i][j] = INF;
        }
        adj[i][i] =0;
    } 
    for(int i=0;i<m;i++){
        int a, b, c; cin>>a>>b>>c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
    }

    floyd();
    cout<<adj[0][n-1]<<"\n";
    
    return 0;

}