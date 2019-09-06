#include <bits/stdc++.h>
using namespace std;
#define MAXN 5e5 + 100
#define INF 1e9 + 10
#define MOD 1
typedef pair<int,int> pii;
typedef unsigned long long int ulli;
template<typename T> bool cmp(T a, T b){return a < b;}

int n;
vector<int> a(MAXN);

// divide and conquer
void merge_sort(int l, int r){
    if(l >= r) return  ;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int lindex = 0, rindex = 0;
    vector<int> lv(a.begin() + l, a.begin() + mid + 1), rv(a.begin() + mid + 1, a.begin() + r + 1);
    lv.push_back(INF), rv.push_back(INF);
    for(int i = l; i <= r; i++){
        if(lv[lindex] > rv[rindex]) a[i] = rv[rindex], rindex++;
        else a[i] = lv[lindex], lindex++;
    }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n - 1);
    for(int i = 0; i < n; i++) cout << a[i] <<" ";
    return 0;
}


