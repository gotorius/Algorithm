#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// 基数ソート
void RadixSort(vector<int> &A) {
    int n = A.size();
    if (n == 0) return;

    // Find the maximum number to know the number of digits
    int maxVal = *max_element(A.begin(), A.end());

    // Perform counting sort for each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> output(n); // Output array
        vector<int> count(10, 0); // Count array for digits

        // Count occurrences of each digit
        for (int i = 0; i < n; i++) {
            count[(A[i] / exp) % 10]++;
        }

        // Update count[i] to contain the position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[(A[i] / exp) % 10] - 1] = A[i];
            count[(A[i] / exp) % 10]--;
        }

        // Copy the output array to A, so that A now contains sorted numbers according to current digit
        for (int i = 0; i < n; i++) {
            A[i] = output[i];
        }
    }
}