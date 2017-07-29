#include <iostream>
using namespace std;
int main(){
	int n, k, m, left, right;
	cin >> n >> m >> k;
	int a[n+1];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	right = m+1;
	left = m-1;
	while(right <= n){
		if(a[right] != 0 && a[right] <= k){
			break;
		}
		right++;
	}

	while(left >= 1){
		if(a[left] != 0 && a[left] <= k){
			break;
		}
		left--;
	}
	if(left > 0 && right <= n){
		if(right-m < m-left){
			cout << 10*(right-m) << endl;
		}
		else{
			cout << 10*(m-left) << endl;
		}
	}
	else if(right <= n){
		cout << 10*(right-m) << endl;
	}
	else{
		cout << 10*(m-left) << endl;
	}

	return 0;

}