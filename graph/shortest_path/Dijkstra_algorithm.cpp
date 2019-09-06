#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 + 10)
#define INF 1e9 + 10
#define MOD (ulli)((1<<31) + 1)
typedef unsigned long long int ulli;

int n;
vector< vector< pair<int,int> > > adj(MAXN);
vector<int> minpath(MAXN, INF);
vector<bool> completed(MAXN, 0);
multiset< pair<int,int> > s;
// Dijkstra algorithm : find shortest path to all vertex from a given node , O(V^2 + E)

void dijkstra(int u){
    for(int i = 0; i < adj[u].size(); i++){
        if(completed[adj[u][i].second]) continue;
        minpath[adj[u][i].second] = min(minpath[adj[u][i].second], minpath[u] + adj[u][i].first);
    }
    int mini = INF, minindex = -1;
    for(int i = 0; i < n; i++)
        if(!completed[i] && minpath[i] < mini) mini = minpath[i], minindex = i;
    if(minindex != -1) completed[u] = 1, dijkstra(minindex);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    n = 6;
    adj[0].push_back(make_pair(8, 1));
    adj[0].push_back(make_pair(2, 2));
    adj[0].push_back(make_pair(4, 3));
    adj[1].push_back(make_pair(8, 0));
    adj[1].push_back(make_pair(7, 2));
    adj[1].push_back(make_pair(2, 4));
    adj[2].push_back(make_pair(2, 0));
    adj[2].push_back(make_pair(7, 1));
    adj[2].push_back(make_pair(1, 3));
    adj[2].push_back(make_pair(3, 4));
    adj[2].push_back(make_pair(9, 5));
    adj[3].push_back(make_pair(4, 0));
    adj[3].push_back(make_pair(1, 2));
    adj[3].push_back(make_pair(5, 5));
    adj[4].push_back(make_pair(2, 1));
    adj[4].push_back(make_pair(3, 2));
    adj[5].push_back(make_pair(9, 2));
    adj[5].push_back(make_pair(5, 3));
    minpath[0] = 0, completed[0] = 1;
    dijkstra(0);
    for(int i = 0; i < n; i++) cout << minpath[i] <<" ";
    return 0;
}
