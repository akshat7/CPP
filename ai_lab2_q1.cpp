#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int main()
{
	int test, n;
	
	
	cin >> test;
	while(test--)
	{
		cin >> n;
		vector< vector<int> > initial, final;
		initial.resize(n, vector<int>(n, 0));
		for(int i = 0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cin >> initial[i][j];
			}
			// cout << endl;
		}
		
		for(int i = 0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cin >> final[i][j];
			}
			// cout << endl;
		}
		
		for(int i = 0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout << initial[i][j] << ' ';
			}
			cout << endl;
		}
		
	}
	return 0;
}