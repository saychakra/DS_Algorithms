#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r){
	int i = l, j = m+1, k = 0;
	int *temp = (int *)malloc(sizeof(int)*(r-l+1));
	//vector<int> temp(r-l+1);
	while(i <= m && j <= r){
		if(a[i] < a[j]){
			temp[k++] = a[i];
			i++;
		}
		else{
			temp[k++] = a[j];
			j++;
		}
	}
	while(i <= m){
		temp[k++] = a[i];
		i++;
	}
	while(j <= r){
		temp[k++] = a[j];
		j++;
	}
	for(i = 0; i < k; i++){
		a[i+l] = temp[i];
	}
}

void mergeSort(int a[], int l, int r){
	int m;
	if(l < r){
		m = (l + r) / 2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
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
	mergeSort(a,0,n-1);
	printArray(a,n);
	return 0;
}