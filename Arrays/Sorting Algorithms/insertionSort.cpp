#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n){
	int i , j;
	for(i = 1; i < n; i++){
		int temp = a[i];
		for(j = i-1; j >= 0; j--){
			if(a[j] > temp)
				a[j+1] = a[j];
			else
				break;
		}
		a[j+1] = temp;
	}
}

void printArray(int *a, int n){
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main(){
	int n;
	cout << "Enter the number of elements you wish to enter: ";
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// int n = sizeof(a)/sizeof(a[0]);
	insertionSort(arr,n);
	printArray(arr,n);
	return 0;
}