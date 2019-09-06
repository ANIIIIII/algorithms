#include <bits/stdc++.h>
using namespace std;
#define MAXN 10 + 10
#define INF (int)1e9 + 10
typedef long long int lli;
bool cmp(pair< pair<int,int> , int > a, pair< pair<int,int> , int >  b){return a.second < b.second;}

int n, m, start, endi;
vector< vector< pair<int,int> > > adj(MAXN);
vector< vector<int> > d(MAXN, vector<int>(MAXN, INF)), p(MAXN, vector<int>(MAXN, -1));

// dynamic programing
// dp(k, i, j) = min(dp(k - 1, i, j), dp(k - 1, i, k) + dp(k - 1, k, j))

void Floyd_Warshall(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
}

void print_path(int x, int y){
    while(y != x){
        cout << y << " ";
        y = p[x][y];
    }
    cout << x << "\n";
    cout << dp[start][endi] << "\n";
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0, x, y, t; i < m; i++){
        cin >> x >> y >> t;
        adj[x].push_back(make_pair(t, y));
        d[x][y] = t;
        p[x][y] = x;
    }
    cin >> start >> endi;
    Floyd_Warshall();
    print_path(start, endi);
    return 0;
}
