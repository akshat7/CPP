#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	float n = -1, sum;
	int i;
	while(true)
	{
		sum = 0;
		scanf("%f", &n);
		if(n == 0)
		{
			break;
		}
		for(i=2; sum < n; i++)
		{
			sum += 1.0/i;
		}
		printf("%d card(s)\n", i-2);
	}
	
	return 0;
}