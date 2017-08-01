#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
	int pivot = a[high], k=-1, temp;
	for(int i=0; i<high; i++){
		if(a[i] <= pivot){
			k++;
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
	temp = a[k+1];
	a[k+1] = a[high];
	a[high] = temp;
	return k+1;
}

void quick_sort(int a[], int low, int high){
	if(low < high){
		int p = partition(a, low, high);
		quick_sort(a, low, p-1);
		quick_sort(a, p+1, high);
	}
}

int main(){
	int n, i, p;
	cin >> n;
	int a[n];
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	quick_sort(a, 0, n-1);
	for(i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
}