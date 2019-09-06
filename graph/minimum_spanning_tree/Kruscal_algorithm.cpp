#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1000 + 10)
#define MAXM (int)(50 + 10)
#define INF 1e9 + 10
#define MOD (ulli)((1<<31) + 1)
typedef unsigned long long int ulli;

bool cmp(pair<int, pair<int,int> > a, pair<int, pair<int,int> > b){
    if(a.first == b.first){
        if(a.second.first == b.second.first) return a.second < b.second;
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

int n, m;
vector<int> s(MAXN);
vector< pair<int, pair<int,int> > > edge;
vector< pair<int,int> > p;

void kruscal(){
    for(int i = 0; i < n; i++) s[i] = i;
    sort(edge.begin(), edge.end(), cmp);
    for(int i = 0; i < n - 1; i++){
        int x = edge[i].second.first, y = edge[i].second.second;
        while(s[x] != x) x = s[x];
        while(s[y] != y) y = s[y];
        if(x == y) continue;
        s[edge[i].second.second] = s[edge[i].second.first];
        p.push_back(make_pair(edge[i].second.first, edge[i].second.second));
    }
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0, a, b, d; i < m; i++){
        cin >> a >> b >> d; 
        edge.push_back(make_pair(d, make_pair(a, b)));
    }
    kruscal();
    for(int i = 0; i < p.size(); i++) cout << p[i].first <<" "<< p[i].second << "\n";
    return 0;
}



