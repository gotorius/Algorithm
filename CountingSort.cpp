#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// 計数ソート
void CountingSort(vector<int> &A, int k) {
    int n = A.size();
    vector<int> C(k + 1, 0);
    vector<int> B(n);

    //　カウント配列の初期化
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    //　累積和
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // 出力配列の構築
    // 安定ソート（元の順序を保つ）のため、後ろから処理。
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    // 元の配列に結果をコピー
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

/* 時間計算量
O(n + k)

n：入力配列 A の要素数

k：要素の最大値（≒取りうる値の範囲の幅）*/


/*詳細な内訳：
C[A[i]]++ でカウント → O(n)

C[i] += C[i-1] で累積和 → O(k)

出力配列を構築 → O(n)

元の配列にコピー → O(n)

合計：O(n + k)*/