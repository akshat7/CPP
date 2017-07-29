#include<bits/stdc++.h>
using namespace std;
long long search_rotated(vector<long long> a, long long low, long long high, long long x){
    // cout << low << ' ' << high << endl;
    if(low == high && x != a[low]){
        return -1;
    }
    long long mid = (low+high)/2;
    // cout << " --- " << mid << endl; 
    if(x == a[mid]){
        // cout << "Returning\n";
        return mid;
    }
    if(a[mid] > a[low] && a[mid-1] < a[mid] && a[low] < a[mid-1]){
        if(x < a[mid] && x >= a[low]){
            return search_rotated(a, low, mid, x);
        }
        else{
            return search_rotated(a, mid+1, high, x);
        }
    }
    else{
        if(x > a[mid] && x <= a[high]){
            return search_rotated(a, mid+1, high, x);
        }
        else{
            return search_rotated(a, low, mid, x);
        }
    }
}
int main()
{
	long long t, n, x, i;
	cin >> t;
	while(t--){
	    cin >> n;
	    vector<long long> a(n);
	    for(i=0; i<n; i++){
	        cin >> a[i];
	    }
	    cin >> x;
	   // for(i=0; i<n; i++){
	   //     if(x == a[i]){
	   //         cout << i << endl;
	   //         break;
	   //     }
	   // }
	    cout << search_rotated(a, 0, n-1, x) << endl;
	   // if(i == n){
	   //     cout << -1 << endl;
	   // }
	    
	}
	return 0;
}