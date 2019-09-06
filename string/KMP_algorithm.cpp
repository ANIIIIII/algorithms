#include <bits/stdc++.h>
using namespace std;
#define MAXN (int)(1e5 + 10)
#define INF 1e9 + 10
#define MOD (ulli)((1<<31) + 1)
typedef unsigned long long int ulli;

string s, S;
vector<int> kmp(MAXN, 0);

// KMP algorithm : to find whether a string is the substring of another string , O(n + m)

void construct_KMP_array(){
    for(int i = 1, j = 0; i < s.length(); i++){
        while(s[i] != s[j] && j != 0) j = kmp[j - 1];
        if(s[i] == s[j]) kmp[i] = ++j;
    }
}

bool sol(){
    for(int i = 0, j = 0; i < S.length(); i++){
        while(S[i] != s[j] && j != 0) j = kmp[j - 1];
        if(S[i] == s[j]) j++;
        if(j == s.length()) return 1;
    }
    return 0;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> S;
    construct_KMP_array();
    if(sol()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
