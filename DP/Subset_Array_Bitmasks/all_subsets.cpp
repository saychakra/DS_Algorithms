/*
 * Basically, bitmasking will allow us to calculate all possible
 * combinations of a subset for a given value of N, where 
 * N = subset size. 
 *
 * EG: Set = {A, B, C}
 * Subsets are: 
 * {}           0 0 0       0
 * {A}          0 0 1       1
 * {B}          0 1 0       2
 * {C}          1 0 0       4
 * {A, B}       0 1 1       3      
 * {A, C}       1 0 1       5
 * {B, C}       1 1 0       6
 * {A, B, C}    1 1 1       7  
 *
 * So values are basically from 0 to 2^N - 1 (N = subset size)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Set contains 5 elements as: {A, B, C, D, E}" << endl;
    cout << "Max value of subset should not obviously exceed 5" << endl;
    char set[5] = {'A', 'B', 'C', 'D', 'E'};
    cout << "Enter the size of the subarrays: ";
    int N;  cin >> N; // size of the subset
    assert (N <= 5);
    int total = 1 << N; // this is basically 2^N
    for(int mask = 0; mask < total; ++mask) { // mask will contain all the subsets
        for(int i = 1; i < N; ++i) {
            int f = 1 << i; // this basically sets the bit at the appropriate place
            if((f & mask) != 0) { // this checks with the mask which bit is set. If 0, then none is set. Otherwise the relevant bit is returned 
                cout << set[i] << " ";
            }
        }
        cout << endl;
    }
    cout << "There are " << total << " UNIQUE subsets as shown above." << endl;
    cout << "NOTE: THE FIRST SUBSET IS A {}, WHICH IS PRINTED BY A BLANK SPACE" << endl;
    return 0;
}
