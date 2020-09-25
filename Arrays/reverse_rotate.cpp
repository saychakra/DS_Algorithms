#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> arr, int d) {
    vector<int> temp;
    for(int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }
    reverse(temp.begin(), temp.end());
    vector<int> temp2;
    for (int i = d; i < arr.size(); i++)
        temp2.push_back(arr[i]);
    reverse(temp2.begin(), temp2.end());
    vector<int> final_vector;
    for(int i = 0; i < temp.size(); i++) 
        final_vector.push_back(temp[i]);
    for (int i = 0; i < temp2.size(); i++)
        final_vector.push_back(temp2[i]);
    reverse(final_vector.begin(), final_vector.end());
    cout << "Printing the vector after " << d << " rotations: " << endl;
    for(int i = 0; i < final_vector.size(); i++) {
        cout << final_vector[i] << " ";
    }
}

int main() {
    int n, d;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Enter the rotation value: ";
    cin >> d;
    left_rotate(arr, d % arr.size());
    return 0;
}