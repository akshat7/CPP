#include <iostream>
#include <cstdio>

using namespace std;

bool coprime(int n, int N);

int main()
{
	long long int t, n, largest;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);
		if(n%2==1)
		{
			largest = n/2;
		}
		else
		{
			if((n/2)%2==0)
			{
				largest = n/2 - 1;
			}
			else
			{
				largest = n/2 - 2;
			}
		}
		printf("%lld\n", largest);
	}
	return 0;
}