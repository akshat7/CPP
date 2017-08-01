#include <bits/stdc++.h>
using namespace std;
int main(){
	long long x, y, n, i, level;
	scanf("%lld", &n);
	vector<long long> a(n);
	for(i=0; i<n; i++){
		scanf("%lld %lld", &x, &y);
		a[i] = min(x, y);
	}
	sort(a.begin(), a.end());
	level = 1;
	for(i=0; i<n; i++){
		if(a[i] >= level){
			a[i] = level;
			level++;
			// cout << a[i] << ' ';
		}
		else{
			a[i] = -1;
		}
	}
	// cout << endl;
	cout << level-1 << endl;
	return 0;
}