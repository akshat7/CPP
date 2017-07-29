#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, h, command, idx=0, crane=0, count;
	cin >> n >> h;
	vector<long long> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	cin >> command;
	while(command != 0){
		switch(command){
			case 1:
				if(idx>0){
					idx--;
				}
				break;
			case 2:
				if(idx < n-1){
					idx++;
				}
				break;
			case 3:
				if(crane == 0 && a[idx] > 0){
					crane = 1;
					// cout << a[idx] << endl;
					a[idx]--;
					// cout << a[idx] << endl;
				}
				break;
			case 4:
				if(crane == 1 && a[idx] < h){
					crane = 0;
					// cout << a[idx] << "kkkkkkk" << endl;
					a[idx]++;
					// cout << a[idx] << endl;
				}
				break;

			default:
				break;
		}
		// cout << "case" << command << "crane" << crane << endl;
		cin >> command;
	}
	for(int i=0; i<n; i++){
		cout << a[i] << ' ';
	}
	cout << endl;
	return 0;
}