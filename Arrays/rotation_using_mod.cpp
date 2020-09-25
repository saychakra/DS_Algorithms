#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, index;
    cout << "Enter the number of elements you wish to enter: ";
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; v.push_back(x);
    }
    cout << "Enter the index for rotation: ";
    cin >> index;
    for(int i = index; i < (index + v.size()); i++) {
        cout << v[i % v.size()] << " ";
    }

    return 0;
}