#include <bits/stdc++.h>
using namespace std;
#define MAXN 10 + 10
#define INF (int)1e9 + 10
typedef long long int lli;
bool cmp(pair< pair<int,int> , int > a, pair< pair<int,int> , int >  b){return a.second < b.second;}

vector< vector< pair<int,int> > > adj(MAXN); 
priority_queue< pair<int,int> > q;
vector<int> p(MAXN, INF);

void dfs(){
    while(!q.empty()){
        int u, v;
        u = q.top().second, v = q.top().second, q.pop();
        while(v > p[u] && !q.empty()) u = q.top().second, v = q.top().first, q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            if(p[adj[u][i].second] > p[u] + adj[u][i].first){
                p[adj[u][i].second] = p[u] + adj[u][i].first;
                q.push(make_pair(p[adj[u][i].second], adj[u][i].second));
            }
        }
    }
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0, x, y, t; i < m; i++){
        cin >> x >> y >> t;
        adj[x].push_back(make_pair(t, y));
    }
    int start;
    cin >> start;
    for(int i = 0; i < n; i++){
        if(i != start) q.push(make_pair(INF, i));
        else q.push(make_pair(0, start));
    }
    p[start] = 0;
    dfs();
    for(int i = 0; i < n; i++) cout << p[i] << " ";
    return 0;
}

