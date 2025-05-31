#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

// バケットソート
void BucketSort(vector<int> &A, int bucketSize) {
    if (A.empty()) return;

    // Find the maximum and minimum values in A
    int maxVal = *max_element(A.begin(), A.end());
    int minVal = *min_element(A.begin(), A.end());

    // Calculate the number of buckets
    int bucketCount = (maxVal - minVal) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    // Distribute the elements into buckets
    for (int num : A) {
        int index = (num - minVal) / bucketSize;
        buckets[index].push_back(num);
    }

    // Sort each bucket and concatenate the results
    A.clear();
    for (auto &bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        A.insert(A.end(), bucket.begin(), bucket.end());
    }
}