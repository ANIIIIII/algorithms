#include <iostream>
#include <vector>
#define MAXN 20
using namespace std;

int n;
vector<int> a(MAXN);


void selection_sort(){
    for(int i = 0; i < n; i++){
        int mini = a[i], minindex = i;
        for(int j = i; j < n; j++)
            if(a[j] < mini) mini = a[j], minindex = j;
        a.erase(a.begin() + minindex);
        a.insert(a.begin() + i, mini);
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
