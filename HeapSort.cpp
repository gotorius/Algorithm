#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// ヒープソート

int left(int i){
    return 2*i;
};

int right(int i){
    return 2*i+1;
}

int parent(int i){
    return i/2;
}

void MaxHeapify(vector<int> &A, int i, int n){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l <= n && A[l] > A[largest]) largest = l;
    if(r <= n && A[r] > A[largest]) largest = r;
    if(largest != i){
        swap(A[i], A[largest]);
        MaxHeapify(A, largest, n);
    }
}
void HeapSort(vector<int> &A){
    int heapsize = A.size();
    for(int i = heapsize/2; i >= 1; i--){
        MaxHeapify(A, i, heapsize);
    }
    for(int i = heapsize; i >= 2; i--){
        swap(A[1], A[i]);
        heapsize--;
        MaxHeapify(A, 1, heapsize);
    }
}

int main(void){

}