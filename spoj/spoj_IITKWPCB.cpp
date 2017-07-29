#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool coprime(int n, int N);

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int largest = 1;
		for(int i = 2; i<=n/2; i++)
		{
			if (coprime(i, n))
			{
				largest = i;
			}
		}
		printf("%d\n", largest);
	}
	return 0;
}

bool coprime(int n, int N)
{
	for(int i=2; i<=n; i++)
	{
		if (n % i == 0 && N % i == 0)
		{
			return false;
		}
	}
	return true;
}
