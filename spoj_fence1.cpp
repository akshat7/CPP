#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	while(1)
	{
		float l, ans;
		scanf("%f", &l);

		if(l == 0)
		{
			break;
		}

		ans = l*l/(2*3.14159);
		printf("%.2f\n", ans);

	}
	return 0;
}