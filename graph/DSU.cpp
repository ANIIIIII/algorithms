#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
#define MAXN (int)(1000 + 10)
#define MAXM (int)(50 + 10)
#define INF 1e9 + 10
#define MOD (ulli)((1<<31) + 1)
typedef unsigned long long int ulli;


int n, m;
vector< vector<int> > adj(MAXN);
vector<int> s(MAXN);
vector<bool> visited(MAXN, 0);

void set_collapsing(int u){
    for(int i = 0; i < adj[u].size(); i++){
        if(visited[adj[u][i]]) continue;
        visited[adj[u][i]] = 1;
        s[adj[u][i]] = s[u];
        set_collapsing(adj[u][i]);
    }
}

void DSU(){
    for(int i = 0; i < n; i++) s[i] = i;
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        set_collapsing(i);
    }
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DSU();
    for(int i = 0; i < n; i++) cout << s[i] << " ";
    return 0;
}


