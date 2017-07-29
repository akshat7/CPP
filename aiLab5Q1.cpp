/*

1
2 4
iit2014003 7 iit2014004 iit2014026 iit2014070 iit2014087 iit2014093 iit2014106 iit2014119
iit2014004 7 iit2014003 iit2014026 iit2014070 iit2014087 iit2014093 iit2014106 iit2014119
iit2014026 7 iit2014003 iit2014004 iit2014070 iit2014087 iit2014093 iit2014106 iit2014119
iit2014070 6 iit2014003 iit2014004 iit2014026 iit2014093 iit2014106 iit2014119
iit2014087 6 iit2014003 iit2014004 iit2014026 iit2014093 iit2014106 iit2014119
iit2014093 7 iit2014003 iit2014004 iit2014026 iit2014070 iit2014087 iit2014106 iit2014119
iit2014106 7 iit2014003 iit2014004 iit2014026 iit2014070 iit2014087 iit2014093 iit2014119
iit2014119 7 iit2014003 iit2014004 iit2014026 iit2014070 iit2014087 iit2014093 iit2014106

*/


#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int m, n, flag;
string arrangement[1000][1000];
map<string, vector<string> > friendMap;
vector<string> studentList;

bool areFriends(string a, string b)
{
	if(find(friendMap[a].begin(), friendMap[a].end(), b) != friendMap[a].end())
	{
		return true;
	}
	return false;
}

bool isPossible(int i, int j, string student)
{
	int count = 0;

	if(i==0 && j==0)
	{
		count++;
	}

	if((j-1)>=0 && (areFriends(student, arrangement[i][j-1])))
	{
		count++;
	}

	// if((j+1)<n && (areFriends(student, arrangement[i][j+1]) || arrangement[i][j-1] == ""))
	// {
	// 	count++;
	// }

	if((i-1)>=0 && (areFriends(student, arrangement[i-1][j])))
	{
		count++;
	}

	// if((i+1)<m && (areFriends(student, arrangement[i+1][j]) || arrangement[i][j-1] == ""))
	// {
	// 	count++;
	// }

	// if((i+1) < m && (j+1) < n && (areFriends(student, arrangement[i+1][j+1]) || arrangement[i][j-1] == ""))
	// {
	// 	count++;
	// }

	if((i-1)>=0 && (j-1)>=0 && (areFriends(student, arrangement[i-1][j-1])))
	{
		count++;
	}

	// if((i+1) < m && (j-1) > 0 && (areFriends(student, arrangement[i+1][j-1]) || arrangement[i][j-1] == ""))
	// {
	// 	count++;
	// }

	if((i-1)>=0 && (j+1) < n && (areFriends(student, arrangement[i-1][j+1])))
	{
		count++;
	}

	if(count == 0)
	{
		return false;
	}
	return true;
}



void printMatrix()
{

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << arrangement[i][j] << " " ;
		}
		cout << endl;
	}

}

map<string, vector<string> > getInput()
{
	int total = m*n, friendCount;
	string student, friends;
	map<string, vector<string> > myMap;
	
	for(int i=0; i<total; i++)
	{
		cin >> student;
		cin >> friendCount;
		
		for(int j=0; j<friendCount; j++)
		{
			cin >> friends;
			myMap[student].push_back(friends);
		}
	}
	return myMap;
}

void arrange(int x, int y)
{
	string student;
	int total = m*n;
	//cout << flag << endl;
	cout << x << ' ' << y << endl;
	for(int i=x*n + y; i<total; i++)
	{
		//cout << flag/n << endl;
		//flag++;
		student = studentList[x*n + y];
		//flag++;

		
		if(isPossible(x, y, student))
		{
			arrangement[x][y] = student;
			//cout << x << ' ' << y << ' ' << arrangement[x][y] << endl;
		}
		else
		{
			if(x < m && y < n-1)
			{
				arrange(x, (y+1));
			}
			else if(x < m-1 && y >= n)
			{
				y = 0;
				arrange(x+1, y);
			}
			else
			{
				break;
			}
		}
	}
}

int main()
{
	int test;
	cin >> test;
	while(test--)
	{
		cin >> m >> n;
		friendMap = getInput();

		//iterate through map keys
		for(const auto &item : friendMap)
		{
			studentList.push_back(item.first);
		}

		
		flag = 0;
		arrange(0, 0);
		printMatrix();
		

		
	}
	return 0;
}
