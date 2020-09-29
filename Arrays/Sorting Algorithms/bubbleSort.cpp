#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		int f = 0;
		for(int j = 0; j < n-i-1; j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				f = 1;
			}
		}
		if(f == 0)
			break;
	}
}

void printArray(int *a, int n){
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main(){
	int a[] = {4,8,0,1,7,2,8,8,3};
	int n = sizeof(a)/sizeof(a[0]);
	bubbleSort(a,n);
	printArray(a,n);
	return 0;
}
