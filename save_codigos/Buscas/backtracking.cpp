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


//Chessboard and Queens
// bool vali(vector<vector<int>>& camp, int row, int col){
//     for(int i=0; i<col; i++){
//         if(camp[row][i]==1) return false;
//     }
//     int l=row;
//     int r=col;
//     while(l>=0&&r>=0){
//         if(camp[l][r]==1) return false;
//         l--; r--;
//     }
//     l=row; r=col;
//     while(l<8&&r>=0){
//         if(camp[l][r]==1) return false;
//         l++; r--;
//     }
//     return true;
    
// }

// void solvequeen(vector<vector<int>>& camp, int j, int& ans){
//     if(j==8){
//         ans++; return;
//     }
//     for(int i=0; i<8; i++){
//         if(camp[i][j]==-1) continue;
//         if(vali(camp, i, j)){
//             camp[i][j]=1;
//             solvequeen(camp, j+1, ans);
//             camp[i][j]=0;
//         }
        
//     }
//     return;   
// }


// signed main(){
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     #ifndef ONLINE_JUDGE
//         freopen("input.txt", "r", stdin);
//         freopen("output.txt", "w", stdout);
//     #endif

//     vector<vector<int>> a;
//     for(int i=0; i<8; i++){
//         vector<int> c;
//         string b; cin>>b;
//         for(int j=0; j<8; j++){
//             if(b[j]=='*') c.push_back(-1);
//             else c.push_back(0);
//         }
//         a.push_back(c);
//     }
//     int ans=0;
//     solvequeen(a, 0, ans);
//     cout<<ans<<"\n";

//     return 0;
// }


//easy sudoku
bool vali(vector<string>& camp, int row, int col, int c){
    for(int i=0; i<9; i++){
        if(camp[row][i]==c)return false;
        else if(camp[i][col]==c) return false;
        else if(camp[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}


bool solvesudoku(vector<string>& camp, int i, int j){
    if(i==9) return true;
    if(j==9) return solvesudoku(camp, i+1, 0);
    if(camp[i][j]!='0') return solvesudoku(camp, i, j+1); 
    for(char c = '1'; c<='9'; c++){
        if(vali(camp, i, j, c)){
            camp[i][j]=c;
            if (solvesudoku(camp, i, j+1)) return true;
            camp[i][j]='0';
        }
    }
    return false;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--){
        vector<string> a;
        for(int i=0; i<9; i++){
            string temp;
            for(int j=0; j<9; j++){
                int x; cin>>x; temp+=(x+'0');
            }
            a.push_back(temp);
        }
        bool ans = solvesudoku(a, 0, 0);
        if(ans){
            for(int i=0; i<9; i++){
                for(int j=0; j<9; j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else cout<<"No solution"<<"\n";
        string lix;
        getline(cin, lix);
    }
    return 0;
}