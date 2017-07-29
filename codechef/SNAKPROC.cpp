#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n, i, flag;
	string s;
	cin >> t;
	while(t--){
		cin >> n >> s;
		stack<char> stk;
		flag = 0;
		for(i=0; i<n; i++){
			if(s[i] == 'H' && stk.empty()){
				stk.push(s[i]);
			}
			else if((s[i] == 'H' && !stk.empty()) || (s[i] == 'T' && stk.empty())){
				flag = 1;
				break;
			}
			else if((s[i] == 'T') && !stk.empty()){
				stk.pop();
			}
		}
		if(!stk.empty()){
			flag = 1;
		}
		if(flag == 0){
			cout << "Valid\n";
		}
		else{
			cout << "Invalid\n";
		}
	}
	return 0;
}