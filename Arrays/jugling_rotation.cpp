#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n, int d) {
    for (int i = 0; i < __gcd(d, n); i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;

            if (k == i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main() {
    int n, d;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of rotations: ";
    cin >> d;
    rotate(arr, n, d);
    cout << "\nAfter rotation: ";
    for(int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}