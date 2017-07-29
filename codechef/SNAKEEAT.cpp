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
			count = 0;
			for(i=0; i<size; i++){
				if(b[i] >= x){
					count++;
				}
				else{
					break;
				}
			}
			while(count < size && (b[count] + (size-count-1)) >= x){
				while((count < size) && (a[count] < x)){
					b.pop_back();
					size--;
					a[count]++;
				}
				if(a[count] >= x){
					count++;
				}
			}
			cout << count << endl;
		}

	}
	return 0;
}