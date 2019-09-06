#include <iostream>
#include <vector>
#define MAXN 20
using namespace std;

int n;
vector<int> a(MAXN);


void quick_sort(int leftbound, int rightbound){
    //divid and conquer
    if(abs(rightbound - leftbound) <= 1) return  ;
    //partition
    int pivot = a[rightbound], pindex = rightbound;
    for(int i = leftbound; i < rightbound && i < pindex; i++){
        if(a[i] > pivot){
            a.insert(a.begin() + (pindex--), a[i]);
            a.erase(a.begin() + (i--));
        }
    }
    swap(a[rightbound], a[pindex]);
    //recursion
    quick_sort(leftbound, pindex - 1);
    quick_sort(pindex + 1, rightbound);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    heap_sort();
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}

