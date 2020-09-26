#include <bits/stdc++.h>
using namespace std;

const int N=1e5;
int n;
// st size can be 2n+1 or to be on the safe side just take N
// vector<int> st((2*n)+1);
vector<int> st(2*N);

void build(vector<int> arr) {
    for(int i = 0; i < n; i++) 
        st[n+i] = arr[i];

    for(int i = n-1; i > 0; --i) 
        st[i] = st[(2*i)] + st[(2*i)+1];
}

int sumRange(int l, int r) {
    int res = 0;
    for(l += n, r += n; l < r; l /= 2, r /= 2) {
        if((l % 2) != 0) 
            // to have range (l to r both inclusive)
            res += st[++l];
            // if r is to be excluded
            // res += st[l++];
        if((r % 2) != 0) 
            res += st[--r];
    }
    return res;
}

int slowSum(int l, int r, vector<int> arr) {
    int sum = 0;
    for(int i = l; i <= r; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    cout << "Array size: "; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; arr.push_back(x);
    }
    int l, r;
    cout << "Enter l, r: " << endl;
    cin >> l >> r;
    cout << "Slow sum: " << slowSum(l, r, arr) << endl;
    build(arr);
    cout << "Segment tree sum: " << sumRange(l, r) << endl;
    return 0;
}
