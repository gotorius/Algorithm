#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// 挿入ソート
void InsertionSort(vector<int> &A) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

/* アルゴリズムの概要

最初の要素（インデックス0）は既に整列済みとみなす。

次の要素を取り、それまでの整列済み部分に適切な位置に挿入する。

配列の最後まで繰り返す*/