#include <bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int> A, B, other, neg;
	vector<int> a,b;
	int n, k, i, temp, max=0, skew_num, t1, t2;
	cin >> n >> k;
	for(i=0; i<n; i++){
		cin >> temp;
		A.push(temp);
		a.push_back(temp);
		if(max<temp){
			max = temp;
		}
	}
	for(i=0; i<n; i++){
		cin >> temp;
		B.push(temp);
		b.push_back(temp);
		if(max<temp){
			max = temp;
		}
	}
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	if(a[k]>b[k]){	
			other=B;
			while(!A.empty()){
				neg.push(-1*A.top());
				A.pop();
			}
		
	}
	else{
			other=A;
			while(!B.empty()){
				neg.push(-1*B.top());
				B.pop();
			}
	}
	while(k--){
		if( other.top() > -neg.top() ){
			t1 = -other.top();
			t2 = -neg.top();
			other.pop();
			neg.pop();
			other.push(t2);
			neg.push(t1);
		}
		else 
			break;
		
	}
	cout << max+other.top() << endl;
	return 0;
}