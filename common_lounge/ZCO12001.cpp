#include <bits/stdc++.h>
using namespace std;
int main(){
	long n, i, cur_depth, max_depth, cur_len, max_len, num, latest, flag=0;
	cin >> n;
	vector<long> a(n), start, close;
	cur_depth = max_depth = 0;
	for(i=0; i<n; i++){
		cin >> a[i];
		if(a[i] == 1){
			cur_depth++;
			if(cur_depth >= max_depth){
				start.push_back(i);
				num++;
				max_depth = cur_depth;
			}
		}
		else{
			cur_depth--;
			if(cur_depth == 0){
				close.push_back(i);
			}
		}
	}
	max_len = cur_len = 0;
	for(i=0; i<num; i++){
		cur_len = 0;
		for(long j=start[i]; j<close[j]; j++){
			cur_len++;
			if(cur_len > max_len){
				max_len = cur_len;
				latest = start[i];
			}
		}
	}
	cout << max_depth << ' ' << start[0] << ' ' << max_len << ' ' << latest << endl;
	return 0;
}