#include <bits/stdc++.h>
using namespace std;
#define MAXN 11
#define INF 1e9 + 10
#define MOD 1e9 + 7
typedef long long int lli;
typedef unsigned long long int ulli;
template<typename T> bool cmp(T a, T b){if(a.first != b.first) return a.first < b.first; return a.second < b.second;}


int n, m;
int dpc[MAXN * MAXN][MAXN * MAXN] = {0};

ulli C(int x, int y){
    if(x == 1 || y == 0 || x == y) return 1;
    return (dpc[x][y] == 0)? dpc[x][y] = C(x - 1, y - 1) + C(x - 1, y) : dpc[x][y];
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cout << C(n, m);
    return 0;
}

