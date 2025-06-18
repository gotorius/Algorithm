#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// クイックソート

void printarray(const vector<int>& A) {
    for (int x : A) cout << x << " ";
    cout << endl;
}

void quicksort(vector<int> &A, int first, int last) {
    int x = A[(first + last) / 2];
    int i = first, j = last;
    while (1) {
        while (A[i] <= x && i < last) i++;
        while (A[j] >= x && j > first) j--;
        if (i >= j) break;
        swap(A[i], A[j]);
        printarray(A);
        i++; j--;
    }
    if (first < i-1) quicksort(A, first, i-1);
    if (j+1 < last) quicksort(A, j+1, last);
}

int main(void) {
    vector<int> A = {7,6,5,8,4,3,2,1};
    int n = A.size();
    printarray(A);
    quicksort(A, 0, n - 1);
    cout << endl;
    return 0;
}

/*  実行結果
3 2 6 8 5 1 7 4 
3 2 6 1 5 8 7 4 
1 2 6 3 5 8 7 4
*/

/*最悪の場合
7 6 5 8 4 3 2 1 
3 6 5 8 4 7 2 1 
3 4 5 8 6 7 2 1 
*/