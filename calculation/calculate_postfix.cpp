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
stack<int> s;

int main(void){
ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            int x, y;
            x = s.top(),s.pop(), y = s.top(), s.pop();
            if(str[i] == '+') x += y;
            else if(str[i] == '-') x -= y;
            else if(str[i] == '*') x *= y;
            else x /= y;
            s.push(x);
        }else
            s.push(str[i] - '0');
    }
    cout << s.top();
    return 0;
}
