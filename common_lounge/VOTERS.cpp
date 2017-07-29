#include <bits/stdc++.h>
using namespace std;
int main(){
	int n1, n2, n3, id, k, count=0;
	cin >> n1 >> n2 >> n3;
	// vector<int> a1(n1), a2(n2), a3(n3);
	map<int, int> a;
	for(int i=0; i<n1+n2+n3; i++){
		cin >> id;
		if(a.find(id) != a.end()){
			a[id]++;
		}
		else{
			a[id] = 1;
		}
	}
	for(auto itr = a.begin(); itr != a.end(); itr++){
		if(itr->second>1){
			count++;
		}
	}
	cout << count << endl;
	for(auto itr = a.begin(); itr != a.end(); itr++){
		if(itr->second>1){
			cout << itr->first << endl;
		}
	}

	return 0;
}