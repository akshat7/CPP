#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, k, i, j, count;
	// cin >> n >> k;
	scanf("%lld %lld", &n, &k);
	vector<long long> a(n);
	for(i=0; i<n; i++){
		// cin >> a[i];
		scanf("%lld", &a[i]);
	}
	count = 0;
	sort(a.rbegin(), a.rend());
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[i] - a[j] >= k){
				count+=n-j;
				break;
			}
		}
	}
	// cout << count << endl;
	printf("%lld\n", count);
	return 0;
}