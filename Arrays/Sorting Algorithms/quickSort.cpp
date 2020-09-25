#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int partition(int a[], int l, int r){
	int pivot = a[l];
	int d = l, u = r;
	while(1){
		while(a[d] <= pivot && d < r) 
			d++;
		while(a[u] > pivot)
			u--;
		if(d < u){
			swap(a[d],a[u]);
			/*int temp = a[d];
			a[d] = a[u];
			a[u] = temp;*/
		}
		else 
			break;
	}
	swap(a[l],a[u]);
	/*int temp = a[l];
	a[l] = a[u];
	a[u] = temp;*/
	return u;
}

void quickSort(int a[], int l, int r){
	int p;
	if(l < r){
		p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
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
	quickSort(a,0,n-1);
	printArray(a,n);
	return 0;
}