#include <bits/stdc++.h>
using namespace std;
#define MAXN 1e4 + 100
#define INF 1e9 + 10
#define MOD 1
typedef vector<int> V;
typedef vector< vector<int> > VV;
typedef pair<int,int> pii;
typedef unsigned long long int ulli;
template<typename T> bool cmp(T a, T b){return a < b;}

int n, m, scccount = 0;
stack<int> st;
vector<bool> visited1(MAXN, 0), visited2(MAXN, 0);
VV adj(MAXN), radj(MAXN), scc(MAXN);

void dfs2(int u){
    visited2[u] = 1;
    scc[scccount].push_back(u);
    for(int i = 0; i < radj[u].size(); i++){
        if(visited2[radj[u][i]]) continue;
        dfs2(radj[u][i]);
    }
}

void dfs1(int u){
    visited1[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        if(visited1[adj[u][i]]) continue;
        dfs1(adj[u][i]);
    }
    st.push(u);
}

void Kosaraju_algorithm(){
    for(int i = 0; i < n; i++){
        if(visited1[i]) continue;
        dfs1(i);
    }
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        if(visited2[temp]) continue;
        dfs2(temp);
        scccount++;
    }
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
    Kosaraju_algorithm();
    for(int i = 0; i < scccount; i++){
        for(int j = 0; j < scc[i].size(); j++) cout << scc[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
