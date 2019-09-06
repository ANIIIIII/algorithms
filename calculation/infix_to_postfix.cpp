#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <string>
using namespace std;
#define MAXN 2e5

string str, a;
stack<char> s;

bool cmpprecedence(char ch){
    if(s.top() == '(') return 0;
    int p = 0, c = 0;
    if(s.top() == '*' || s.top() == '/') p = 1;
    if(ch == '*' || ch == '/') c = 1;
    return p >= c;
}

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(') s.push(str[i]);
        else if(str[i] == ')'){
            while(!s.empty() && s.top() != '(') a += s.top(), s.pop();
            s.pop();
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            while(!s.empty() && cmpprecedence(str[i])) a += s.top(), s.pop();
            if(str[i] != '(' && str[i] != ')') s.push(str[i]);
        }else
            a += str[i];
    }
    while(!s.empty()){
        a += s.top();
        s.pop();
    }
    cout << a;
    return 0;
}

