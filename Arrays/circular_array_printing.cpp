#include <bits/stdc++.h>
using namespace std;

void print_CircularArray(vector<int> v, int index) {
    int n = v.size();
    for(int i = index; i < (n + index); i++) {
        cout << v[i % n] << " ";
    }
}

int main() {
    int n, index;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x;  cin >> x; v.push_back(x);
    }
    // we will be using mod to print the circular array. The major help would be the linear time and constant space complexity
    cout << "Enter the index from which you wish to print: ";
    cin >> index;
    cout << "\nPrinting the array from index" << index << " in a circular fashion: " << endl;
    print_CircularArray(v, index-1);
    return 0;
}