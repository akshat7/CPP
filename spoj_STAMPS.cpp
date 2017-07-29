#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	long t, n, f, i, flag=0;
	scanf("%ld", &t);
	while(t--)
	{
		flag++;
		scanf("%ld %ld", &n, &f);
		int stamps[f];
		
		for(i=0; i<f; i++)
		{
			scanf("%d", &stamps[i]);
		}

		size_t size = f;
		sort(stamps, stamps + size, greater<int>());

		long sum = 0;

		for(i=0; i < f; i++)
		{
			if(sum >= n)
			{
				break;
			}

			sum += stamps[i];
		}
		
		printf("Scenario #%ld:\n", flag);
		
		if(sum < n)
		{
			cout << "impossible" << endl;
		}
		else
		{
			printf("%ld\n",i);
		}

		cout << endl;

		// for(i = 0; i < size; ++i)
		// {
		// 	cout << stamps[i] << ' ';
		// }
		// cout << sum << ' ' << i << endl;

	}
	return 0;
}