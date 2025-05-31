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

    // Count occurrences of each element
    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    // Update C to contain the position of each element in the output array
    for (int i = 1; i <= k; i++) {
        C[i] += C[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    // Copy the sorted elements back to A
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}