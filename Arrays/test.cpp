#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<int> v1;
    vector<int> v2;
    int n1, n2;
    cout << "Enter the size of vector 1 and 2: ";
    cin >> n1 >> n2;
    for(int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
    }
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }
    vector<int> m;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), m.begin());
    for(int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }
    return 0;
}