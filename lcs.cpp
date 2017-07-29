#include <iostream>

using namespace std;

int main(){

	int n, m, i, j;
	// cin >> n >> m;
	
	// char a[n], b[m];
	// cin >> a >> b;

	char a[] = "AGGTAB";
  	char b[] = "GXTXAYB";

	m = strlen(b);
	n = strlen(a);

	int lcs[n+1][m+1];
	for(i=0; i<=n; i++){
		for(j=0; j<=m; i++){
			if(i == 0 || j == 0){
				lcs[i][j] = 0;
				cout << "Here\n";
			}
			else if(a[i] == b[j]){
				lcs[i][j] = 1+lcs[i-1][j-1];
			}
			else{
				lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
			}
		}
		
	}
	cout << lcs[n][m] << endl;
	return 0;

}