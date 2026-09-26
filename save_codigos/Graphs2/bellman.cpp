#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
#define tuple tuple<int,int, int>
#define vt vector<tuple>
#define pqueue priority_queue<tuple, vector<tuple>, greater<tuple>>
const int bit = 0x3f;
const int nbit = 0xc0;
const int INF_mn = 0xc0c0c0c0c0c0c0c0;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e3;

int n, m;
int dist[MAXN];
int pai[MAXN];
vector<int> ciclo;
void bellman1(int u, vt& adj){
    memset(dist, bit, sizeof(dist));
    memset(pai, -1, sizeof(pai));
    dist[0] = 0;
    for(int i=0; i<n-1; i++){
        for(auto [u,v,w]: adj){
            if(dist[v]>dist[u]+w){
                dist[v] = dist[u]+w;
                pai[v] = u;
            }
        }
    }
    int idx1= -1;
    for(auto [u, v, w]: adj){
        if(dist[v]>dist[u]+w){
            dist[v] = dist[u]+w;
            pai[v] = u;
            idx1=v;
            break;
        }
    }
    if(idx1==-1) return;
    for(int i=0; i<n; i++) idx1= pai[idx1];
    int va = idx1;
    ciclo.push_back(idx1+1);
    while(idx1!=pai[va]){
        ciclo.push_back(pai[va]+1);
        va = pai[va];
    }
    ciclo.push_back(idx1+1);
    reverse(ciclo.begin(), ciclo.end());
}

//High Score (Valor máximo), funciona para valor mínimo também
bool bellman(int i, vt& adj){
    memset(dist, nbit, sizeof(dist));
    dist[i]= 0;
    for(int i =0; i<n-1; i++){
        for(auto [u, v, w]: adj){
            if(dist[u]!=INF_mn&&dist[v]<dist[u]+w){
                dist[v] = dist[u]+w;
            } 
        }
    }
    for(int i =0; i<n; i++){
        for(auto [u, v, w]: adj){
            if(dist[u]!=INF_mn&&dist[v]<dist[u]+w){
                dist[v] = INF;
            }
        }
    }
    if(INF==dist[n-1]) return false;
    return true;
}



signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed<<setprecision(15); 
    cin>>n>>m;
    vector<tuple> p(m); 
    for(int i=0;i<m;i++){
        int a, b, c; cin>>a>>b>>c;
        p[i] = {a-1, b-1, c};
    }

    bellman1(0, p);
    if(!(int)ciclo.size()) cout<<"NO\n";
    else{
        cout<<"YES\n";
        for(auto u:ciclo) cout<<u<<" ";
        cout<<"\n";
    }
    
    return 0;

}