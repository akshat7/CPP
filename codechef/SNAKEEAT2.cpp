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
int main(){
	long long t, n, i, flag, q, count, size, temp, x;
	cin >> t;
	while(t--){
		cin >> n >> q;
		flag = 0;
		vector<long long> a(n), b(n);
		for(i=0; i<n; i++){
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		while(q--){
			b = a;
			size = n;
			cin >> x;
			count = size - (lower_bound(b.rbegin(), b.rend(), x) - b.rbegin());
			while(count < size && (b[count] + size-count-1) >= x){
				temp = x - b[count];
				if(b[count] < x){
					size -= temp;
					b[count++]=x;
				}
			}
			cout << count << endl;
		}

	}
	return 0;
}