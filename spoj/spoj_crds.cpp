#include <iostream>

using namespace std;

int main()
{
	int t;
	long long ans, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld", &n);
		ans = n*(n+1) + ((n-1)*n)/2;
		ans = ans%1000007;
		printf("%lld\n", ans);
	}
	return 0;
}