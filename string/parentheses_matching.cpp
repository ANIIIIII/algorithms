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


int main(void){
ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    stack<int> pstack;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ')'){
            if(!pstack.empty() && pstack.top() == '(') pstack.pop();
            else{puts("No"); return 0;}
        }
        else if(str[i] == '}'){
            if(!pstack.empty() && pstack.top() == '{') pstack.pop();
            else{puts("No"); return 0;}
        }
        else if(str[i] == ']'){
            if(!pstack.empty() && pstack.top() == '[') pstack.pop();
            else{puts("No"); return 0;}
        }
        else pstack.push(str[i]);
    }
    if(!pstack.empty()) puts("No");
    else puts("Yes");
    return 0;
}
