/* 
2
5 2
21 9 5 8 10
10
15
5 1
1 2 3 4 5
100
*/

#include <bits/stdc++.h>
using namespace std;

long long bin_search(vector<long long> a, vector<long long> psum, long long lo, long long hi, long long x){
	long long mid, lsum, hsum, s;
	if(hi == lo){
		return 0;
	}
	mid = (hi+lo)/2;
	hsum = psum[hi] - psum[mid];
	lsum = psum[mid];
	s = (hi-mid)*(x);
	if((s-hsum) <= mid - lo + 1){
		return (hi-mid);
	}
	return bin_search(a, psum, mid+1, hi, x);
}

int main(){
	long long t, n, i, flag, q, count, size, temp, x;
	cin >> t;
	while(t--){
		cin >> n >> q;
		flag = 0;
		vector<long long> a(n), psum(n-1);
		for(i=0; i<n; i++){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		psum[0] = a[0];

		for(i=1; i<n-1; i++){
			psum[i] = a[i] + psum[i-1];
		}
		while(q--){
			cin >> x;
			temp = (lower_bound(a.begin(), a.end(), x) - a.begin());
			// cout << temp << ' ' << a[temp] << endl;
			count = n-temp;

			if(temp == 0){
				cout << n << endl;
				continue;
			}

			count += bin_search(a, psum, 0, temp-1, x);

			cout << count << endl;
		}

	}
	return 0;
}