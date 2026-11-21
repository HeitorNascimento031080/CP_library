#include <bits/stdc++.h>
using namespace std;
#define int long long

// Prime Multiples

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(k);
    for(int& i:a) cin>>i;
    string sa(k, '0');
    int ans =0;
    for(int i=k-1; i>=0; i--){
        sa[i]='1';
        string temp = sa;
        if((k-i)&1){
            do{ 
                int val =1;
                for(int j=0; j<k; j++){
                    if(temp[j]=='1'){
                        if(val>n/a[j]){
                            val = n+1;
                            break;
                        } 
                        val*=a[j]; 
                    } 

                } 
                ans+=n/val;
            }while(next_permutation(temp.begin(), temp.end()));
        }
        else{
            do{
                int val =1;
                for(int j=0; j<k; j++){
                    if(temp[j]=='1'){
                        if(val>n/a[j]){
                            val = n+1;
                            break;
                        } 
                        val*=a[j]; 
                    } 
                    
                } 
                ans-=n/val;             
            }while(next_permutation(temp.begin(), temp.end())); 
        }
    }
    cout<<ans<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t =1;
    // cin>>t;
    while(t--) solve(); 
    return 0;
}