#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 + 5)
#define INF 2e5
typedef long long int lli;

int power(int n, int k){
    if(k == 0) return 1;
    else if(k % 2 == 0){
        int temp = power(n, k / 2);
        return temp * temp;
    }
    else return n * power(n, k - 1);
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << power(29, 26);
    return 0;
}

