#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
	int t, n, i, low, mid, high;
	cin >> t;
	while(t--){
	    cin >> n;
	    vector<int> a(n);
	    for(i=0; i<n; i++){
	        cin >> a[i];
	    }
	    for(i=0; i<n; i++){
	        if(a[i] != 0){
	            low = i;
	            break;
	        }
	    }
	    // cout << low << endl;
	    mid = low+1;
	    high = n-1;
	    while(mid <= high){
	        if(a[mid] == 0){
	            swap(a[low], a[mid]);
	            low++;
	        }
	        if(a[mid] == 2){
	            swap(a[high], a[mid]);
	            high--;
	        }
	        if(a[low] == 0){
	        	low++;
	        }
	        if(a[mid] == 1){
	            mid++;
	        }
	        if(a[high] == 2){
	        	high--;
	        }
	        
	    }
	   // sort(a.begin(), a.end());
	   
	    for(i=0; i<n; i++){
	        cout << a[i] << ' ';
	    }
	    cout << endl;
	}
	return 0;
}