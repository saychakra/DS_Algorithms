#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define ull unsigned long long

int main() {
    //converting decimal numbers to binary and binary to decimals
    // say input is an integer number
    int n;
    cout << "Enter the decimal value: ";
    cin >> n;
    string binary = bitset<8>(n).to_string();
    cout << "The corresponding binary equivalent: " <<  binary << endl;

    // converting the binary number back to decimal
    // precisely will be converting to unsigned long long int
    // (cause it makes more sense)
    cout << "Converting the binary number again to the binary equivalent: " << endl;
    bitset<8> dec_val_bits(binary);
    ull dec_val = dec_val_bits.to_ullong();
    cout << "Converted back to decimal: " << dec_val << endl;
}
