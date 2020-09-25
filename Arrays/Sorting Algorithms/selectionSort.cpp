#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n){
	int minIndex;
	for(int i = 0; i < n-1; i++){
		minIndex = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[minIndex])
				minIndex = j;
		}
		swap(a[i],a[minIndex]);
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
	selectionSort(a,n);
	printArray(a,n);
	return 0;
}