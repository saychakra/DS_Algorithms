#include <bits/stdc++.h>
using namespace std;

void showList(list <int> l) {
    list <int>::iterator it;
    for(it=l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

int addLists(list<int> l1, list<int> l2) {
    int num1=0, num2=0;
    list<int>::iterator it;
    
    int size1 = l1.size();
    int multiplier1 = size1 - 1;
    
    int size2 = l2.size();
    int multiplier2 = size2 - 1;
    
    for(it = l1.begin(); it != l1.end(); it++) {
        num1 += *it * pow(10, multiplier1);
        multiplier1--;
    }
    for (it = l2.begin(); it != l2.end(); it++) {
        num2 += *it * pow(10, multiplier2);
        multiplier2--;
    }
    cout << "Number 1 = " << num1 << endl;
    cout << "Number 2 = " << num2 << endl;
    return (num1 + num2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list <int> l1;
    list <int> l2;

    //first linked list
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(0);
    
    // second linked list
    l2.push_back(1);
    l2.push_back(0);
    l2.push_back(5);
    
    int sum = addLists(l1, l2);

    cout << "The sum of the contents of the two lists are: " << sum << endl;
    return 0;
}