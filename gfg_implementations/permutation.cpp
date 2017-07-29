#include<bits/stdc++.h>
using namespace std;

vector<string> find_permutations(string s){
    int n = s.length(), l;
    vector<string> v;
    string alph, s2;
    char temp;
    if(n > 2){
        for(int i=0; i<n; i++){
            vector<string> a;
            alph = s[i];
            s2 = s;
            s2.erase(s2.begin()+i);
            a = find_permutations(s2);
            l = a.size();
            for(int j=0; j<l; j++){
                a[j] = alph + a[j];
                v.push_back(a[j]);
            }

        }
    }
    else{
        v.push_back(s);
        temp = s[0];
        s[0] = s[1];
        s[1] = temp;
        v.push_back(s);
    }
    return v;
}

int main()
{
	int t, n, i;
	string s;
	vector<string> v;
	cin >> t;
	while(t--){
	    cin >> s;
	    v = find_permutations(s);
	    n = v.size();
        // cout << n << endl;
        sort(v.begin(), v.end());
	    for(i=0; i<n; i++){
	        cout << v[i] << ' ';
	    }
        cout << endl;
	}
	return 0;
}