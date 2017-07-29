#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long t, n, sum;
	cin >> t;
	while(t--)
	{
		cin >> n;
		
		sum = 0;
		sum = n*n + (n-1)*(n-1);

		cout << sum << endl;

	}
}