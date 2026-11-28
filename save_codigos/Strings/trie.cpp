#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define vvi vector<vector<int>>
using mtuple = tuple<int, int>;
#define vt vector<tuple>
#define pqueue priority_queue<mtuple, vector<mtuple>, greater<mtuple>>
const int MAXN  =1e6+4;
const int INF_mx = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
const int alf = 26+26;
const int LOG = 30;
struct Node{
    signed nxt[alf] {};
    signed subtree_cont = 0;
    signed end_cont = 0;
};
 
int to_id(char ch){
    if(ch>='a'&&ch<='z') return ch -'a';
    return (ch-'A')+26;
}
 
struct Trie{
    vector<Node> tr;
    Trie() : tr(1) {}
 
    void add_w(string& str){
        int cur =0;
        for(auto ch:str){
            int id = to_id(ch);
            if(!tr[cur].nxt[id]){
                int len = (int)tr.size();
                tr[cur].nxt[id] = len;
                tr.emplace_back();
            }
            tr[cur].subtree_cont+=1;
            cur = tr[cur].nxt[id];
        }
        tr[cur].subtree_cont+=1;
        tr[cur].end_cont++;
    }
 
    int qy_prefix(string& str){
        int cur = 0;
        for(auto ch:str){
            if(!tr[cur].nxt[to_id(ch)]) return 0;
            cur = tr[cur].nxt[to_id(ch)];
        }
        return tr[cur].subtree_cont;
    }
 
    int cont_w(string& str){
        int cur = 0;
        for(auto ch:str){
            if(!tr[cur].nxt[to_id(ch)]) return 0;
            cur = tr[cur].nxt[to_id(ch)];
        }
        return tr[cur].end_cont;
    }
 
    void erase_w(string& str){
        if(cont_w(str)==0) return;
        int cur=0;
        for(auto ch:str){
            tr[cur].subtree_cont--;
            cur = tr[cur].nxt[to_id(ch)];
        }
        tr[cur].subtree_cont--;
        tr[cur].end_cont--;
    }
};

struct Node2{
    signed nxt[2] {};
    signed cont = 0;
};

struct Trie2{
    vector<Node2> tr;
    Trie2() : tr(1) {}

    void add_num(int num){
        int cur =0;
        for(int b = LOG; b>=0; b--){
            int id = (num>>b)&1;
            if(!tr[cur].nxt[id]){
                int len = (int)tr.size();
                tr[cur].nxt[id] = len;
                tr.emplace_back();
            }
            tr[cur].cont+=1;
            cur = tr[cur].nxt[id];
        }
        tr[cur].cont+=1;
    }

    void erase_num(int num){
        int cur = 0;
        for(int b = LOG; b>=0; b--){
            int id = (num>>b)&1;
            tr[cur].cont--;
            cur = tr[cur].nxt[id];
        }
        tr[cur].cont--;
    } 

    int max_xor(int num){ //subarray: precisa usar prefix xor
        int cur = 0; int ans =0;
        for(int b = LOG; b>=0; b--){
            int id = (num>>b)&1;
            int nxt_d = tr[cur].nxt[!id];
            if(nxt_d&&tr[nxt_d].count>0){
                ans|=(1LL<<b);
                cur = nxt_d;
            }
            else{
                cur = tr[cur].nxt[id];
            }
        }
        return ans;
    }

    int min_xor(int num){ //subarray: precisa usar prefix xor
        int cur = 0; int ans =0;
        for(int b = LOG; b>=0; b--){
            int id = (num>>b)&1;
            int nxt_s = tr[cur].nxt[id];
            if(nxt_s&&tr[nxt_s].count>0){
                cur = nxt_s;
            }
            else{
                ans|=(1LL<<b);
                cur = tr[cur].nxt[!id];                
            }
        }
        return ans;
    }

};
