#include <iostream>
#include <vector>
#define MAXN 20
using namespace std;

int n;
vector<int> a(MAXN);

void insertion_sort(){
    for(int i = 0; i < n; i++){
        int j, temp = a[i];
        for(j = 0; j <= i && a[i] > a[j]; j++);
        a.erase(a.begin() + i);
        a.insert(a.begin() + j, temp);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    heap_sort();
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
