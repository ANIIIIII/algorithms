#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1000 + 10)
#define MAXM (int)(50 + 10)
#define INF 1e9 + 10
#define MOD (ulli)((1<<31) + 1)
typedef unsigned long long int ulli;

int n, m;
vector< vector< pair<int,int> > > adj(MAXN);
vector<int> p(MAXN, INF);
vector<bool> visited(MAXN, 0);


void prim(int u){
    int mini = INF, minindex = -1;
    for(int i = 0; i < adj[u].size(); i++){
        if(visited[adj[u][i].second]) continue;
        p[adj[u][i].second] = min(p[adj[u][i].second], adj[u][i].first);
        if(adj[u][i].first < mini) mini = adj[u][i].first, minindex = i;
    }
    if(minindex == -1) return  ;
    visited[adj[u][minindex].second] = 1;
    prim(adj[u][minindex].second);
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b, d; i < m; i++){
        cin >> a >> b >> d; 
        adj[a].push_back(make_pair(d, b));
        adj[b].push_back(make_pair(d, a));
    }
    visited[0] = 1;
    p[0] = 0;
    prim(0);
    for(int i = 0; i < n; i++) cout << p[i] << "\n";
    return 0;
}


