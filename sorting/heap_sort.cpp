#include <iostream>
#include <vector>
#define MAXN 20
using namespace std;

int n;
vector<int> a(MAXN);

void heap_sort(){
    //building minheap
    vector<int> heap;
    heap.push_back(0);
    for(int i = 0; i < n; i++){
        heap.push_back(a[i]);
        int index = heap.size() - 1;
        while(index / 2 >= 1){
            if(heap[index] < heap[index / 2]) swap(heap[index], heap[index / 2]), index /= 2;
            else break;
        }
    }
    //popping mnheap
    for(int i = 0; heap.size() >= 1; i++){
        a[i] = heap[1];
        swap(*(++heap.begin()), *(--heap.end()));
        heap.erase(--heap.end());
        int index = 1;
        while(2 * index < heap.size()){
            int swapindex = -1;
            if(heap[index] > heap[2 * index]) swapindex = 2 * index;
            if(2 * index + 1 < heap.size() && heap[2 * index] > heap[2 * index + 1]) swapindex = 2 * index + 1;
            if(swapindex == -1) break;
            swap(heap[index], heap[swapindex]), index = swapindex;
        }
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


