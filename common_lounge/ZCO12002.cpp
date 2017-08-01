#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, x, y, v, w, i, diff, d, t1, t2;
	// cin >> n >> k;
	scanf("%lld %lld %lld", &n, &x, &y);
	map<long long, long long> contest, tv, tw;
	vector<long long> V(x), W(y);
	for(i=0; i<n; i++){
		// cin >> a[i];
		scanf("%lld %lld", &v, &w);
		contest[v] = w;
	}
	for(i=0; i<x; i++){
		scanf("%lld", &V[i]);
	}
	for(i=0; i<y; i++){
		scanf("%lld", &W[i]);
	}
	
	sort(V.begin(), V.end());
	sort(W.begin(), W.end());

	for(auto itr = contest.begin(); itr != contest.end(); itr++){
		diff = LLONG_MAX;
		for(i=0; i<x; i++){
			d = itr->first - V[i];
			if(diff > d && d >= 0){
				diff = d;
				t1 = V[i];
			}
		}
		tv[itr->first] = t1;
		diff = LLONG_MAX;
		for(i=0; i<y; i++){
			d = W[i] - itr->second;
			if(diff > d && d >= 0){
				diff = d;
				t2 = W[i];
			}
		}
		tw[itr->second] = t2;
	}
	for(auto itr = contest.begin(); itr != contest.end(); itr++){
		diff = LLONG_MAX;
		d = tw[itr->second] - tv[itr->first] + 1;
		if(diff > d){
			diff = d;
		}
	}
	cout << diff << endl;
	return 0;
}