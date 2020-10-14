/*
    Author: Sayan Chakraborty
*/

#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = a; i > b; --i)
#define ll int64_t
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vd vector<double>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626


// ============================== templates for reading and printing vectors, comparing to values ==============================
// comparison template
template <class T, class U>
bool are_equal (T a, U b) {
    return (a==b);
}
// input for vector
template <class T, class U>
void read(vector<T> &v, U size) {
    for(int i = 0; i < size; i++) {
        T x; cin >> x; v.push_back(x);
    }
}
// for printing the vector 
template<class T>
void debv(vector<T> &v){
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

// sorting any vector in descending order
template<class T>
void dsort(vector<T> &v) {
    sort(all(v), greater<T>());
}
//=======================
const int MOD = 1'000'000'007;
const int N = 2e6+13, M = N;
//=======================

void solve() {

}


int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);
    
    int t;
	cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
