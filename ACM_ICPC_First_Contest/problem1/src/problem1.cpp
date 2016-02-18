#include <iostream>
#include <string>
using namespace std;
long long zeros = 0;
int n;
string ugly = "1";
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string str;
		int x;
		cin >> str;
		if(str=="0")
		{
			cout << "0";
			return 0;
		}
		else if(str[0]=='1')
		{
			bool isUgly = false;
			for(int j = 1; j< str.size(); j++)
			{
				if(str[j]!='0')
				{
					isUgly = true;
					break;
				}
			}
			if(isUgly)
				ugly = str;
			else
				zeros += str.size()-1;
		}
		else
		{
			ugly = str;
		}
	}
	cout << ugly;
	for(int i = 0; i < zeros; i++)
	{
		cout << "0";
	}
	return 0;
}
