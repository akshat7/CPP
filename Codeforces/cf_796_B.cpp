#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	long long n, k, m, num, a, b, final, i;
	cin >> n >> m >> k;
	vector<long long> h(n+1, 0);
	for(i=0; i<m; i++){
		cin >> num;
		h[num] = 1;
	}
	for(i=0; i<k; i++){
		cin >> a >> b;
		if(h[a]){
			final = a;
			break;
		}
		else if (h[b]){
			final = b;
			break;
		}
		else{
			final = b;
		}
	}
	cout << final << endl;
	return 0;

}