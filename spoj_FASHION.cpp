#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long t, n, i, flag=0;
	scanf("%ld", &t);
	while(t--)
	{
		flag++;
		scanf("%ld", &n);
		int men[n], women[n];
		
		for(i=0; i<n; i++)
		{
			scanf("%d", &men[i]);
		}

		for(i=0; i<n; i++)
		{
			scanf("%d", &women[i]);
		}

		size_t size = n;
		
		sort(men, men + size, greater<int>());
		sort(women, women + size, greater<int>());

		long sum = 0;

		for(i=0; i < n; i++)
		{

			sum += men[i]*women[i];
		}

		cout << sum << endl;

	}
	return 0;
}