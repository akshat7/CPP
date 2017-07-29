#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, i, right, left, swap;
	cin >> n;
	vector<int> a(n);
	
	for(i=0; i<n; i++){
		cin >> a[i];
	}
	right = n-1;
	left = 0;
	while(left < right){
		
		if(a[right]<a[left]){
			swap = a[left];
			a[left] = a[right];
			a[right] = swap;
		}
		if(a[left] == 0){
			left++;
		}
		if(a[right] == 1){
			right--;
		}
	}
	for(i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}