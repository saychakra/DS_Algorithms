#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if(l < n && a[l] > a[largest])
		largest = l;
	if(r < n && a[r] > a[largest])
		largest = r; 
	if(largest != i){
		swap(a[largest],a[i]);
		heapify(a,n,largest);
	}
}

void heapSort(int a[], int n){
	for(int i = n/2 -1; i >= 0; i--)
		heapify(a,n,i);
	for(int i = n-1; i >= 0; i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}

void printArray(int a[], int n){
	cout << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << "   ";
	cout << endl;
}

int main(){
	int a[] = {5,8,9,1,3,2,7,0};
	int n = sizeof(a)/sizeof(a[0]);
	heapSort(a,n);
	printArray(a,n);
	return 0;
}