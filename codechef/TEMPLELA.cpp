#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n, i, flag;
	cin >> t;
	while(t--){
		cin >> n;
		flag = 0;
		vector<int> a(n);
		for(i=0; i<n; i++){
			cin >> a[i];
		}
		if(n%2 == 0 || a[0] != 1){
			cout << "no\n";
			continue;
		}
		// else{
			flag = 0;
			for(i=1; i<n/2; i++){
				if(a[i] - a[i-1] != 1 || a[n-i] != a[i-1]){
					flag = 1;
					cout << "no\n";
					break;
				}
			}
			if(flag == 0){
				cout << "yes\n";
			}

		// }

	}
	return 0;
}