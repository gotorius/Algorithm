#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// 選択ソート
void SelectionSort(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex]) {
                minIndex = j;
            }
        }
        swap(A[i], A[minIndex]);
    }
}

/*アルゴリズムの概要

配列の先頭からスタート。

残りの未ソート部分から最小値を探す。

最小値と現在位置の要素を交換する。

次の位置に移動し、手順2〜3を繰り返す。*/