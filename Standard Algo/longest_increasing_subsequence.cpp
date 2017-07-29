#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n, i, j, max_count = 1;
	cin >> n;
	int a[n], dp[n];
	for(i=0; i<n; i++){
		cin >> a[i];
		dp[i] = 1;
	}

	for(i=1; i<n; i++){
		for(j=0; j<i; j++){
			if(a[j] <= a[i]){
				dp[i] = max(dp[i], dp[j]+1);
				if(max_count < dp[i]){
					max_count = dp[i];
				}
			}
		}
	}

	cout << max_count << endl;

	
	return 0;
}